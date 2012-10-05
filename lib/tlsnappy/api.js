var tlsnappy = require('../tlsnappy'),
    tls = require('tls'),
    util = require('util'),
    net = require('net'),
    os = require('os'),
    http = require('http'),
    Stream = require('stream').Stream;

// Convert protocols array into valid OpenSSL protocols list
// ("\x06spdy/2\x08http/1.1\x08http/1.0")
function convertNPNProtocols(NPNProtocols) {
  // If NPNProtocols is Array - translate it into buffer
  if (Array.isArray(NPNProtocols)) {
    var buff = new Buffer(NPNProtocols.reduce(function(p, c) {
      return p + 1 + Buffer.byteLength(c);
    }, 0));

    NPNProtocols.reduce(function(offset, c) {
      var clen = Buffer.byteLength(c);
      buff[offset] = clen;
      buff.write(c, offset + 1);

      return offset + 1 + clen;
    }, 0);

    NPNProtocols = buff;
  }

  // If it's already a Buffer - store it
  if (Buffer.isBuffer(NPNProtocols)) return NPNProtocols;
};

function Server(options, listener) {
  var self = this;

  net.Server.call(this, this.onconnection.bind(this));

  if (options.NPNProtocols) {
    var npn = convertNPNProtocols(options.NPNProtocols);
  }

  // Create workers
  this.contexts = [];
  this.current = 0;
  this.threads = options.threads || os.cpus().length;
  for (var i = 0; i < this.threads; i++) {
    var context = new tlsnappy.binding.Context();
    if (options.key) context.setKey(options.key);
    if (options.cert) context.setCert(options.cert);
    if (npn) context.setNPN(npn);

    this.contexts.push(context);
  }

  if (listener) this.on('secureConnection', listener);
  this.on('close', function() {
    self.threads = 0;
    self.contexts = [];
  });
};
util.inherits(Server, net.Server);
exports.TLSServer = Server;

exports.createTLSServer = function createTLSServer(options, listener) {
  return new Server(options, listener);
};

function HTTPServer(options, listener) {
  Server.call(this, options, http._connectionListener);

  if (listener) {
    this.addListener('request', listener);
  }
};
exports.Server = HTTPServer;
util.inherits(HTTPServer, Server);

exports.createServer = function createServer(options, listener) {
  return new HTTPServer(options, listener);
};

Server.prototype.onconnection = function onconnection(c) {
  var self = this,
      snappy = new Socket(c, this.contexts[this.current]);

  // Round-robin contexts
  this.current = (this.current + 1) % this.threads;

  snappy.once('init', function() {
    self.emit('secureConnection', snappy);
  });
};

function Socket(c, context) {
  Stream.call(this);

  this.socket = c;
  this.binding = new tlsnappy.binding.Socket(context);

  this._destroySoon = false;
  this.writable = true;
  this.readable = true;
  this.closed = false;
  this.paused = false;
  this._initialized = false;
  this.npnProtocol = null;
  this.init(c);
};
util.inherits(Socket, Stream);
exports.Socket = Socket;

Socket.prototype.init = function init(socket) {
  var self = this;

  // Initialize binding
  this.binding.onedata = function onedata(data) {
    // Data from binding to socket
    return socket.write(data);
  };
  this.binding.oncdata = function oncdata(data) {
    if (data.length === 0) return;

    // Emit data only once initialized
    if (!self._initialized) {
      self.once('init', function() {
        this.emit('data', data);
        if (this.ondata) this.ondata(data, 0, data.length);
      });
      return;
    }

    // Data from binding to user
    self.emit('data', data);
    if (self.ondata) self.ondata(data, 0, data.length);
  };
  this.binding.onclose = function onclose() {
    if (self._destroySoon) {
      socket.destroySoon();
    } else {
      socket.destroy();
    }
    self.emit('end');
    self.binding = null;
    self.closed = true;
  };
  this.binding.oninit = function oninit(npn) {
    self._initialized = true;
    self.npnProtocol = npn;
    self.emit('init');
  };

  // Initialize socket
  socket.on('data', function(data) {
    if (self.binding.encIn(data) === false) c.pause();
  });
  function end() {
    self.end();
  }
  socket.on('close', end);
  socket.on('end', end);
  socket.on('error', end);
  socket.on('timeout', function() {
    self.emit('timeout');
  });
};

Socket.prototype.setTimeout = function setTimeout(ms, callback) {
  this.socket.setTimeout(ms, callback);
};

Socket.prototype.destroySoon = function destroySoon() {
  if (this.closed) return;
  this._destroySoon = true;
  this.end();
};

Socket.prototype.pause = function pause() {
  if (this.paused) return;
  this.paused = true;
};

Socket.prototype.resume = function resume() {
  if (!this.paused) return;
  this.paused = false;
};

Socket.prototype.write = function write(data, enc) {
  // Data from user to binding
  if (!Buffer.isBuffer(data)) {
    data = new Buffer(data, enc);
  }
  return this.binding.clearIn(data);
};

Socket.prototype.destroy = function destroy() {
  this.end();
};

Socket.prototype.end = function end() {
  if (this.closed) return;
  this.closed = true;

  this.binding.close();
};

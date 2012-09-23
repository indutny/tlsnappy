var tlsnappy = require('../tlsnappy'),
    tls = require('tls'),
    util = require('util'),
    net = require('net'),
    os = require('os'),
    http = require('http'),
    Stream = require('stream').Stream;

function Server(options, listener) {
  var self = this;

  net.Server.call(this, this.onconnection.bind(this));

  // Create workers
  this.contexts = [];
  this.current = 0;
  this.threads = options.threads || os.cpus().length;
  for (var i = 0; i < this.threads; i++) {
    var context = new tlsnappy.binding.Context();
    if (options.key) context.setKey(options.key);
    if (options.cert) context.setCert(options.cert);

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

  self.emit('secureConnection', snappy);
};

function Socket(c, context) {
  Stream.call(this);

  this.binding = new tlsnappy.binding.Socket(context);
  this.binding.onedata = this.onedata.bind(this);
  this.binding.oncdata = this.oncdata.bind(this);
  this.binding.onhandshake = this.onhandshake.bind(this);
  this.binding.onclose = this.onclose.bind(this);

  this.c = c;

  this._destroySoon = false;
  this.writable = true;
  this.readable = true;
  this.closed = false;
  this.paused = false;
  this.init();
};
util.inherits(Socket, Stream);
exports.Socket = Socket;

Socket.prototype.init = function init() {
  var self = this;

  this.c.on('data', function(data) {
    if (self.binding.encIn(data) === false) c.pause();
  });
  function end() {
    self.end();
  }
  this.c.on('close', end);
  this.c.on('end', end);
  this.c.on('error', end);
  this.c.on('timeout', function() {
    self.emit('timeout');
  });
};

Socket.prototype.setTimeout = function setTimeout(ms, callback) {
  this.c.setTimeout(ms, callback);
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

Socket.prototype.onedata = function onedata(data) {
  // Data from binding to socket
  return this.c.write(data);
};

Socket.prototype.oncdata = function oncdata(data) {
  if (data.length === 0) return;

  // Data from binding to user
  this.emit('data', data);
  if (this.ondata) this.ondata(data, 0, data.length);
};

Socket.prototype.onhandshake = function onhandshake() {
  this.emit('handshake');
};

Socket.prototype.onclose = function onclose() {
  if (this._destroySoon) {
    this.c.destroySoon();
  } else {
    this.c.destroy();
  }
  this.emit('end');
  this.binding = null;
};

Socket.prototype.destroy = function destroy() {
  this.end();
};

Socket.prototype.end = function end() {
  if (this.closed) return;
  this.closed = true;

  this.binding.close();
};

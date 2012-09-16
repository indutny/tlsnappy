var tlsnappy = require('../tlsnappy'),
    util = require('util'),
    net = require('net'),
    http = require('http'),
    Stream = require('stream').Stream;

function Server(options, listener) {
  net.Server.call(this, this.onconnection.bind(this));

  // Create workers
  this.contexts = [];
  this.current = 0;
  this.threads = options.threads || 1;
  for (var i = 0; i < this.threads; i++) {
    var context = new tlsnappy.binding.Context();
    if (options.key) context.setKey(options.key);
    if (options.cert) context.setCert(options.cert);

    this.contexts.push(context);
  }

  if (listener) this.on('secureConnection', listener);
};
util.inherits(Server, net.Server);
exports.Server = Server;

exports.createServer = function createServer(options, listener) {
  return new Server(options, listener);
};

function HTTPServer(options, listener) {
  Server.call(this, options, http._connectionListener);

  if (listener) {
    this.addListener('request', listener);
  }
};
util.inherits(HTTPServer, Server);

exports.createHTTPServer = function createHTTPServer(options, listener) {
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
  this.c.on('close', function() {
    self.end();
  });
  this.c.on('end', function() {
    self.end();
  });
  this.c.on('error', function(err) {
    self.end();
  });
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
};

Socket.prototype.destroy = function destroy() {
  this.end();
};

Socket.prototype.end = function end() {
  if (this.closed) return;
  this.closed = true;

  this.binding.close();
};

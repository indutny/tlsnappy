var tlsnappy = require('../tlsnappy'),
    util = require('util'),
    net = require('net'),
    Stream = require('stream').Stream;

function Server(options, listener) {
  net.Server.call(this, this.onconnection.bind(this));

  this.context = new tlsnappy.binding.Context();
  if (options.key) this.context.setKey(options.key);
  if (options.cert) this.context.setCert(options.cert);

  if (listener) this.on('secureConnection', listener);
};
util.inherits(Server, net.Server);
exports.Server = Server;

exports.createServer = function createServer(options, listener) {
  return new Server(options, listener);
};

Server.prototype.onconnection = function onconnection(c) {
  var self = this,
      snappy = new Socket(c, this.context);

  self.emit('secureConnection', snappy);
};

function Socket(c, context) {
  var self = this;

  Stream.call(this);

  this.binding = new tlsnappy.binding.Socket(context);
  this.binding.onedata = this.onedata.bind(this);
  this.binding.oncdata = this.oncdata.bind(this);
  this.binding.onhandshake = this.onhandshake.bind(this);
  this.binding.onclose = this.onclose.bind(this);

  this.c = c;
  this.c.on('data', function(data) {
    if (self.binding.encIn(data) === false) c.pause();
  });
  this.c.on('end', function() {
    self.end();
  });
  this.c.on('error', function(err) {
  });

  this.writable = true;
  this.readable = true;
  this.closed = false;
  this.paused = false;
};
util.inherits(Socket, Stream);
exports.Socket = Socket;

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
};

Socket.prototype.onhandshake = function onhandshake() {
  this.emit('handshake');
};

Socket.prototype.onclose = function onclose() {
  this.c.destroy();
  this.emit('end');
};

Socket.prototype.end = function end() {
  if (this.closed) return;
  this.closed = true;

  this.binding.close();
};

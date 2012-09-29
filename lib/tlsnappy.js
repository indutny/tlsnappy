var tlsnappy = exports;

// Binding

tlsnappy.binding = require('bindings')('tlsnappy');

// API

tlsnappy.Socket = require('./tlsnappy/api').Socket;
tlsnappy.Server = require('./tlsnappy/api').Server;
tlsnappy.TLSServer = require('./tlsnappy/api').TLSServer;
tlsnappy.createTLSServer = require('./tlsnappy/api').createTLSServer;
tlsnappy.createServer = require('./tlsnappy/api').createServer;

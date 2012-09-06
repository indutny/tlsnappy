var tlsnappy = exports;

// Binding

tlsnappy.binding = require('bindings')('tlsnappy');

// API

tlsnappy.Socket = require('./tlsnappy/api').Socket;
tlsnappy.Server = require('./tlsnappy/api').Server;
tlsnappy.createServer = require('./tlsnappy/api').createServer;

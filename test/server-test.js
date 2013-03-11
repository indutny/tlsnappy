var assert = require('assert'),
    fs = require('fs'),
    tls = require('tls'),
    tlsnappy = require('..');

describe('TLSnappy', function() {
  var options = {
        key: fs.readFileSync(__dirname + '/../keys/server.key'),
        cert: fs.readFileSync(__dirname + '/../keys/server.crt'),
        rejectUnauthorized: false
      },
      server;

  beforeEach(function() {
    server = tlsnappy.createTLSServer(options).listen(44300);
  });

  afterEach(function() {
    server.close();
  });

  it('should accept tls connection', function(callback) {
    server.on('secureConnection', function(c) {
      var data = '';
      c.on('data', function(chunk) {
        data += chunk;
      });

      c.on('end', function() {
        assert.equal(data, 'hello');
        callback();
      });
    });

    var client = tls.connect(44300, options, function() {
      client.end('hello');
    });
  });
});

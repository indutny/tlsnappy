var fs = require('fs'),
    tlsnappy = require('..'),
    spdy = require('spdy');

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt')
};

var server = spdy.createServer(tlsnappy.Server, options, function(req, res) {
  res.end('hello world');
  if (req.url === '/exit') {
    server.close(function() {
      console.log('should be closed');
    });
  }
}).listen(44300, function() {
  console.log('listening');
});

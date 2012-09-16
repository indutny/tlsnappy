var fs = require('fs'),
    tlsnappy = require('..');

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt')
};

var server = tlsnappy.createServer(options, function(req, res) {
  res.end('hello world');
  if (req.url === '/exit') {
    server.close(function() {
      console.log('should be closed');
    });
  }
}).listen(44300, function() {
  console.log('listening');
});

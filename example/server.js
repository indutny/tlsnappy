var fs = require('fs'),
    tlsnappy = require('..');

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt')
};

tlsnappy.createHTTPServer(options, function(req, res) {
  res.end('hello world');
}).listen(44300, function() {
  console.log('listening');
});

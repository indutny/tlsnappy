var fs = require('fs'),
    tlsnappy = require('..');

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt')
};

tlsnappy.createServer(options, function(c) {
  c.on('data', function(data) {
    console.log(data.toString());
  });
  c.write('HTTP/1.1 200 Ok\r\n\r\nhello');
  c.end();
}).listen(44300, function() {
  console.log('listening');
});

var fs = require('fs'),
    os = require('os'),
    cluster = require('cluster'),
    https = require('https'),
    tlsnappy = require('..');


var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt')
};

var big = new Array(1024).join('abc');

function handler(req, res) {
  if (req.url === '/big') {
    return res.end(big);
  }

  res.end('hello world');
  if (req.url === '/exit') {
    server.close(function() {
      console.log('should be closed');
    });
  }
}

if (process.argv[2] === '--https') {
  if (cluster.isMaster) {
    function fork() {
      cluster.fork().on('death', fork);
    }

    for (var i = 0; i < os.cpus().length; i++) {
      fork();
    }
  } else {
    var server = https.createServer(options, handler);
  }
} else {
  var server = tlsnappy.createServer(options, handler);
}

if (!server) return;
server.listen(44300, function() {
  console.log('listening');
});

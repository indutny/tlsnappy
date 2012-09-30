var fs = require('fs'),
    os = require('os'),
    cluster = require('cluster'),
    https = require('https'),
    tlsnappy = require('..'),
    threads = os.cpus().length;

var needsCluster = process.argv[2] === '--https' ||
                   process.argv[2] === '--cluster';

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt'),
  threads: needsCluster ? Math.ceil(Math.sqrt(threads)) : undefined
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

if (needsCluster) {
  if (cluster.isMaster) {
    function fork() {
      cluster.fork().on('death', fork);
    }

    if (process.argv[2] === '--cluster') {
      options.threads = 1;
    } else if (process.argv[2] !== '--https') {
      threads = options.threads;
    }

    for (var i = 0; i < threads; i++) {
      fork();
    }
  } else if (process.argv[2] === '--https') {
    var server = https.createServer(options, handler);
  } else {
    var server = tlsnappy.createServer(options, handler);
  }
} else {
  var server = tlsnappy.createServer(options, handler);
}

if (!server) return;
server.listen(44300, function() {
  console.log('listening');
});

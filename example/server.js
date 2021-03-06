var fs = require('fs'),
    os = require('os'),
    cluster = require('cluster'),
    https = require('https'),
    tlsnappy = require('..'),
    threads = os.cpus().length;

var needsCluster = process.argv[2] === '--https' ||
                   process.argv[2] === '--hybrid' ||
                   process.argv[2] === '--cluster';

var options = {
  key: fs.readFileSync(__dirname + '/../keys/server.key'),
  cert: fs.readFileSync(__dirname + '/../keys/server.crt'),
  threads: needsCluster ? Math.ceil(Math.sqrt(threads)) : undefined
};

var big = new Buffer(new Array(1024).join('abc')),
    verybig = new Buffer(100000);

verybig.fill('A');

function handler(req, res) {
  // Just for benchmarking
  res.writeHead(200, {
    'Server': 'nginx/1.3.6',
    'Content-Type': 'application/octet-stream'
  });

  if (req.url === '/big') {
    return res.end(big);
  }

  if (req.url === '/verybig') {
    return res.end(verybig);
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
server.listen(process.argv[3] || 44300, function() {
  console.log('listening %d', process.pid);
});

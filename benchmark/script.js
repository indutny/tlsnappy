var exec = require('child_process').exec,
    fs = require('fs'),
    async = require('async');

var step = 4,
    r = 1000;

function loadavg() {
  return {
    now: +new Date,
    avg: parseFloat(fs.readFileSync('/proc/loadavg')
                      .toString().split(/ /g, 1)[0])
  };
};

function benchmark(server, callback) {
  var c = 4;

  function bench() {
    if (c == 188) return callback();
    if (c == 104) r = 500;

    var avgs = [];

    function tick() {
      avgs.push(loadavg());
    }

    var interval = setInterval(tick, 3000);
    tick();
    exec('siege -b -c ' + c + ' -r ' + r + ' ' + server, function(err, stdout, stderr) {
      clearInterval(interval);

      if (err) throw err;

      tick();

      var mean = 0;
      for (var i = 0; i < avgs.length; i++) {
        mean += avgs[i].avg;
      }
      mean = mean / avgs.length;

      var match = stderr.match(/Transaction rate:\s+(\d+\.\d+)/);
      var rate = match[1];
      console.log(c + ', ' + rate + ', ' + mean);

      c += step;
      bench();
    });
  }

  bench();
};

var servers = {
  'nginx': 'https://localhost:44300/big',
  'default': 'https://localhost:44301/big',
  'hybrid': 'https://localhost:44302/big',
  'cluster': 'https://localhost:44303/big',
  'https': 'https://localhost:44304/big'
};

async.forEachSeries(Object.keys(servers), function(key, callback) {
  console.log('Benchmark start: %s', key);
    benchmark(servers[key], function() {
      console.log('Benchmark end: %s', key);
      console.log('-----------------');
      setTimeout(function() {
        callback();
      }, 60000);
    });
}, function() {
  console.log('done');
});

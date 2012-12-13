# TLSnappy

TLS module, but faster! ( [benchmarks][1] )

**Stability: -1**

This module is unstable, things may break and/or unicorns can just jump in front
of you. In case of anything - open issue!

# API

```javascript
var tlsnappy = require('tlsnappy');

// SSL server options
var options = {
  key: Blob,
  cert: Blob,
  shutdownTimeout: 5000, // in ms, (default: 5000)
  handshakeTimeout: 120 * 1000, // in ms, (default: 120 * 1000)
  NPNProtocols: [ 'http/1.1', 'http/1.0' ] // optional, needed for spdy
};

// HTTPS Server
tlsnappy.createServer(options, function(req, res) {
  res.end('hello world');
}).listen(443);

// TLS Server (i.e. raw SSL)
tlsnappy.createTLSServer(options, function(connection) {
  connection.write('hello world');
  connection.end();
});
```

Also everything should work like you're using node's default tls server!

### License

This software is licensed under the MIT License.

Copyright Fedor Indutny, 2012.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
USE OR OTHER DEALINGS IN THE SOFTWARE.

[1]: https://github.com/indutny/tlsnappy/blob/master/benchmark/index.md

# TLSnappy

![Requests per second](https://raw.github.com/indutny/tlsnappy/master/benchmark/tlsnappy-rps.png)
![Time per request](https://raw.github.com/indutny/tlsnappy/master/benchmark/tlsnappy-ms.png)

As you can see tlsnappy has slightly worse results at small concurrency level,
I suppose it's because of round-robin balancing which tlsnappy is using
internally. On all other loads it outperforms default node's tls module in both
requests per second and time per request measurements.

## TLSnappy with cluster

Also, I've included benchmark results of tlsnappy with `cluster` module. It's
significantly slower than both tlsnappy (without cluster) and tls because it was
using only 6-8 cores of my 16 core server. Why was that happening?

`cluster`'s is balancing connections to the first free process. And those 6-8
processes was always free, because tlsnappy does all SSL encryption/decryption
in threads, w/o block event-loop (in contrast to `tls` module, which blocks
event-loop every time it needs to encrypt outcoming/decrypt incoming data).

### 16

```
Concurrency Level:      16
Time taken for tests:   52.107 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1919.14 [#/sec] (mean)
Time per request:       8.337 [ms] (mean)
Time per request:       0.521 [ms] (mean, across all concurrent requests)
Transfer rate:          161.18 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        3    6   3.7      5      44
Processing:     0    2   2.4      2      42
Waiting:        0    2   2.4      2      38
Total:          4    8   4.4      8      48

Percentage of the requests served within a certain time (ms)
  50%      8
  66%      8
  75%      8
  80%      8
  90%      9
  95%     10
  98%     31
  99%     36
 100%     48 (longest request)
```

### 32

```
Concurrency Level:      32
Time taken for tests:   48.083 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2079.75 [#/sec] (mean)
Time per request:       15.386 [ms] (mean)
Time per request:       0.481 [ms] (mean, across all concurrent requests)
Transfer rate:          174.67 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        5   11   5.5      9      72
Processing:     1    5   4.0      4      60
Waiting:        0    4   3.9      4      60
Total:          8   15   6.7     14      88

Percentage of the requests served within a certain time (ms)
  50%     14
  66%     15
  75%     15
  80%     16
  90%     17
  95%     28
  98%     45
  99%     47
 100%     88 (longest request)
```

### 48

```
Concurrency Level:      48
Time taken for tests:   47.558 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2102.70 [#/sec] (mean)
Time per request:       22.828 [ms] (mean)
Time per request:       0.476 [ms] (mean, across all concurrent requests)
Transfer rate:          176.59 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        7   15   7.0     14      65
Processing:     1    7   4.9      6      61
Waiting:        1    6   4.8      5      58
Total:         12   23   8.4     21      80

Percentage of the requests served within a certain time (ms)
  50%     21
  66%     22
  75%     23
  80%     24
  90%     27
  95%     48
  98%     53
  99%     55
 100%     80 (longest request)
```

### 64

```
Concurrency Level:      64
Time taken for tests:   47.208 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2118.29 [#/sec] (mean)
Time per request:       30.213 [ms] (mean)
Time per request:       0.472 [ms] (mean, across all concurrent requests)
Transfer rate:          177.90 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       10   20   8.0     18      63
Processing:     3   10   5.7      9      56
Waiting:        1    8   5.7      7      50
Total:         16   30   9.8     27      80

Percentage of the requests served within a certain time (ms)
  50%     27
  66%     29
  75%     31
  80%     32
  90%     48
  95%     56
  98%     61
  99%     63
 100%     80 (longest request)
```

### 80

```
Concurrency Level:      80
Time taken for tests:   47.423 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2108.68 [#/sec] (mean)
Time per request:       37.938 [ms] (mean)
Time per request:       0.474 [ms] (mean, across all concurrent requests)
Transfer rate:          177.10 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       12   25   9.4     23      97
Processing:     3   12   6.8     11      81
Waiting:        1    9   6.8      8      77
Total:         20   38  11.7     34     122

Percentage of the requests served within a certain time (ms)
  50%     34
  66%     37
  75%     40
  80%     42
  90%     59
  95%     65
  98%     70
  99%     75
 100%    122 (longest request)
```

### 96

```
Concurrency Level:      96
Time taken for tests:   47.133 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2121.64 [#/sec] (mean)
Time per request:       45.248 [ms] (mean)
Time per request:       0.471 [ms] (mean, across all concurrent requests)
Transfer rate:          178.18 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       14   30  10.3     28      94
Processing:     3   15   7.5     13      84
Waiting:        1   11   7.5      9      83
Total:         24   45  12.7     42     114

Percentage of the requests served within a certain time (ms)
  50%     42
  66%     45
  75%     48
  80%     51
  90%     67
  95%     73
  98%     79
  99%     84
 100%    114 (longest request)
```

### 112

```
Concurrency Level:      112
Time taken for tests:   47.113 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2122.56 [#/sec] (mean)
Time per request:       52.767 [ms] (mean)
Time per request:       0.471 [ms] (mean, across all concurrent requests)
Transfer rate:          178.26 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       16   35  10.7     33     100
Processing:     4   17   7.9     16      85
Waiting:        2   12   8.1     10      85
Total:         27   53  13.5     49     131

Percentage of the requests served within a certain time (ms)
  50%     49
  66%     54
  75%     58
  80%     61
  90%     74
  95%     81
  98%     89
  99%     94
 100%    131 (longest request)
```

### 128

```
Concurrency Level:      128
Time taken for tests:   47.440 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2107.92 [#/sec] (mean)
Time per request:       60.723 [ms] (mean)
Time per request:       0.474 [ms] (mean, across all concurrent requests)
Transfer rate:          177.03 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       20   41  12.1     38     103
Processing:     5   20   8.7     18      78
Waiting:        2   14   8.6     12      74
Total:         34   61  14.9     56     130

Percentage of the requests served within a certain time (ms)
  50%     56
  66%     63
  75%     68
  80%     72
  90%     84
  95%     91
  98%     99
  99%    104
 100%    130 (longest request)
```

### 144

```
Concurrency Level:      144
Time taken for tests:   47.465 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2106.82 [#/sec] (mean)
Time per request:       68.349 [ms] (mean)
Time per request:       0.475 [ms] (mean, across all concurrent requests)
Transfer rate:          176.94 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       18   46  13.4     42     126
Processing:     6   23   9.9     21      93
Waiting:        1   16   9.8     14      93
Total:         38   68  16.7     64     186

Percentage of the requests served within a certain time (ms)
  50%     64
  66%     72
  75%     78
  80%     82
  90%     93
  95%    101
  98%    110
  99%    116
 100%    186 (longest request)
```

### 160

```
Concurrency Level:      160
Time taken for tests:   47.160 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2120.45 [#/sec] (mean)
Time per request:       75.456 [ms] (mean)
Time per request:       0.472 [ms] (mean, across all concurrent requests)
Transfer rate:          178.08 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       21   50  13.6     47     123
Processing:     5   25  11.0     23      96
Waiting:        2   18  10.6     15      83
Total:         41   75  17.3     71     159

Percentage of the requests served within a certain time (ms)
  50%     71
  66%     80
  75%     86
  80%     90
  90%    100
  95%    109
  98%    119
  99%    125
 100%    159 (longest request)
```

### 176

```
Concurrency Level:      176
Time taken for tests:   46.249 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2162.21 [#/sec] (mean)
Time per request:       81.398 [ms] (mean)
Time per request:       0.462 [ms] (mean, across all concurrent requests)
Transfer rate:          181.59 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       24   54  13.1     51     115
Processing:     6   27  11.1     25      97
Waiting:        2   20  10.6     17      89
Total:         48   81  17.1     77     171

Percentage of the requests served within a certain time (ms)
  50%     77
  66%     87
  75%     93
  80%     96
  90%    105
  95%    113
  98%    122
  99%    128
 100%    171 (longest request)
```

### 192

```
Concurrency Level:      192
Time taken for tests:   46.285 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2160.54 [#/sec] (mean)
Time per request:       88.867 [ms] (mean)
Time per request:       0.463 [ms] (mean, across all concurrent requests)
Transfer rate:          181.45 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       26   59  14.2     56     130
Processing:     6   30  11.7     28     102
Waiting:        1   21  11.0     19      98
Total:         47   89  18.3     85     182

Percentage of the requests served within a certain time (ms)
  50%     85
  66%     96
  75%    102
  80%    105
  90%    114
  95%    123
  98%    133
  99%    137
 100%    182 (longest request)
```

## HTTPS

### 16

```
Concurrency Level:      16
Time taken for tests:   49.500 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2020.20 [#/sec] (mean)
Time per request:       7.920 [ms] (mean)
Time per request:       0.495 [ms] (mean, across all concurrent requests)
Transfer rate:          169.66 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2    6   1.6      5      46
Processing:     0    2   1.3      2      29
Waiting:        0    2   1.1      1      29
Total:          2    8   2.2      8      48

Percentage of the requests served within a certain time (ms)
  50%      8
  66%      8
  75%      9
  80%      9
  90%     11
  95%     12
  98%     13
  99%     15
 100%     48 (longest request)
```

### 32

```
Concurrency Level:      32
Time taken for tests:   48.343 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2068.53 [#/sec] (mean)
Time per request:       15.470 [ms] (mean)
Time per request:       0.483 [ms] (mean, across all concurrent requests)
Transfer rate:          173.72 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   10   3.0     10      38
Processing:     0    5   2.5      4      30
Waiting:        0    3   2.3      2      29
Total:          2   15   4.3     15      47

Percentage of the requests served within a certain time (ms)
  50%     15
  66%     16
  75%     18
  80%     18
  90%     21
  95%     23
  98%     26
  99%     28
 100%     47 (longest request)
```

### 48

```
Concurrency Level:      48
Time taken for tests:   48.163 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2076.27 [#/sec] (mean)
Time per request:       23.118 [ms] (mean)
Time per request:       0.482 [ms] (mean, across all concurrent requests)
Transfer rate:          174.37 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   16   4.5     15      47
Processing:     0    8   3.5      7      38
Waiting:        0    5   3.4      4      30
Total:          2   23   6.3     22      58

Percentage of the requests served within a certain time (ms)
  50%     22
  66%     25
  75%     26
  80%     28
  90%     31
  95%     35
  98%     39
  99%     41
 100%     58 (longest request)
```

### 64

```
Concurrency Level:      64
Time taken for tests:   47.661 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2098.16 [#/sec] (mean)
Time per request:       30.503 [ms] (mean)
Time per request:       0.477 [ms] (mean, across all concurrent requests)
Transfer rate:          176.21 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   20   6.0     20      64
Processing:     0   10   4.7      9      50
Waiting:        0    6   4.5      5      47
Total:          2   30   8.4     29      79

Percentage of the requests served within a certain time (ms)
  50%     29
  66%     33
  75%     35
  80%     37
  90%     41
  95%     46
  98%     52
  99%     55
 100%     79 (longest request)
```

### 80

```
Concurrency Level:      80
Time taken for tests:   48.063 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2080.62 [#/sec] (mean)
Time per request:       38.450 [ms] (mean)
Time per request:       0.481 [ms] (mean, across all concurrent requests)
Transfer rate:          174.74 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        3   25   7.7     25      70
Processing:     0   13   5.8     11      52
Waiting:        0    8   5.7      6      44
Total:          5   38  10.7     37      92

Percentage of the requests served within a certain time (ms)
  50%     37
  66%     41
  75%     44
  80%     47
  90%     53
  95%     58
  98%     65
  99%     69
 100%     92 (longest request)
```

### 96

```
Concurrency Level:      96
Time taken for tests:   48.826 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2048.11 [#/sec] (mean)
Time per request:       46.872 [ms] (mean)
Time per request:       0.488 [ms] (mean, across all concurrent requests)
Transfer rate:          172.01 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        4   31   9.7     30     116
Processing:     0   16   7.4     14     102
Waiting:        0   10   7.2      7      99
Total:          5   47  13.7     45     146

Percentage of the requests served within a certain time (ms)
  50%     45
  66%     50
  75%     54
  80%     57
  90%     65
  95%     71
  98%     81
  99%     88
 100%    146 (longest request)
```

### 112

```
Concurrency Level:      112
Time taken for tests:   48.476 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2062.87 [#/sec] (mean)
Time per request:       54.293 [ms] (mean)
Time per request:       0.485 [ms] (mean, across all concurrent requests)
Transfer rate:          173.25 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        3   36  10.9     35     113
Processing:     1   18   8.2     16      71
Waiting:        0   12   8.0      9      68
Total:          5   54  15.2     52     134

Percentage of the requests served within a certain time (ms)
  50%     52
  66%     58
  75%     63
  80%     66
  90%     74
  95%     83
  98%     92
  99%     98
 100%    134 (longest request)
```

### 128

```
Concurrency Level:      128
Time taken for tests:   48.213 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2074.14 [#/sec] (mean)
Time per request:       61.712 [ms] (mean)
Time per request:       0.482 [ms] (mean, across all concurrent requests)
Transfer rate:          174.19 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        4   41  12.3     40     111
Processing:     0   21   9.3     18      84
Waiting:        0   13   9.2     10      74
Total:         10   62  17.4     59     146

Percentage of the requests served within a certain time (ms)
  50%     59
  66%     66
  75%     71
  80%     74
  90%     85
  95%     95
  98%    105
  99%    112
 100%    146 (longest request)
```

### 144

```
Concurrency Level:      144
Time taken for tests:   48.739 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2051.73 [#/sec] (mean)
Time per request:       70.185 [ms] (mean)
Time per request:       0.487 [ms] (mean, across all concurrent requests)
Transfer rate:          172.31 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        8   46  14.3     45     134
Processing:     3   24  10.6     21     123
Waiting:        0   15  10.4     11     113
Total:         14   70  19.9     67     176

Percentage of the requests served within a certain time (ms)
  50%     67
  66%     75
  75%     81
  80%     85
  90%     97
  95%    107
  98%    120
  99%    127
 100%    176 (longest request)
```

### 160

```
Concurrency Level:      160
Time taken for tests:   48.989 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2041.26 [#/sec] (mean)
Time per request:       78.383 [ms] (mean)
Time per request:       0.490 [ms] (mean, across all concurrent requests)
Transfer rate:          171.43 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        6   52  15.3     50     143
Processing:     1   27  11.3     24     106
Waiting:        0   17  11.2     12      86
Total:          9   78  21.2     76     184

Percentage of the requests served within a certain time (ms)
  50%     76
  66%     84
  75%     90
  80%     94
  90%    106
  95%    117
  98%    132
  99%    141
 100%    184 (longest request)
```

### 176

```
Concurrency Level:      176
Time taken for tests:   49.098 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2036.76 [#/sec] (mean)
Time per request:       86.412 [ms] (mean)
Time per request:       0.491 [ms] (mean, across all concurrent requests)
Transfer rate:          171.06 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        4   57  17.1     55     170
Processing:     1   30  12.7     26     120
Waiting:        1   18  12.6     14     110
Total:          7   86  23.9     83     218

Percentage of the requests served within a certain time (ms)
  50%     83
  66%     93
  75%     99
  80%    104
  90%    117
  95%    130
  98%    147
  99%    157
 100%    218 (longest request)
```

### 192

```
Concurrency Level:      192
Time taken for tests:   48.953 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    2042.77 [#/sec] (mean)
Time per request:       93.990 [ms] (mean)
Time per request:       0.490 [ms] (mean, across all concurrent requests)
Transfer rate:          171.56 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:       13   62  17.2     61     166
Processing:     3   32  12.8     29     123
Waiting:        1   20  12.9     15      99
Total:         19   94  23.6     91     214

Percentage of the requests served within a certain time (ms)
  50%     91
  66%    101
  75%    107
  80%    112
  90%    125
  95%    137
  98%    151
  99%    162
 100%    214 (longest request)
```

## TLSnappy (cluster)

### 16

```
Concurrency Level:      16
Time taken for tests:   68.432 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1461.31 [#/sec] (mean)
Time per request:       10.949 [ms] (mean)
Time per request:       0.684 [ms] (mean, across all concurrent requests)
Transfer rate:          122.73 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2    7   4.0      7      54
Processing:     0    4   3.0      3      47
Waiting:        0    3   2.9      3      47
Total:          2   11   5.9     11      70

Percentage of the requests served within a certain time (ms)
  50%     11
  66%     14
  75%     15
  80%     16
  90%     17
  95%     18
  98%     19
  99%     30
 100%     70 (longest request)
```

### 32

```
Concurrency Level:      32
Time taken for tests:   64.088 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1560.35 [#/sec] (mean)
Time per request:       20.508 [ms] (mean)
Time per request:       0.641 [ms] (mean, across all concurrent requests)
Transfer rate:          131.04 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   13   7.4     13      64
Processing:     0    8   5.6      7      60
Waiting:        0    7   5.6      6      60
Total:          2   20  11.4     22      81

Percentage of the requests served within a certain time (ms)
  50%     22
  66%     28
  75%     30
  80%     31
  90%     32
  95%     34
  98%     39
  99%     55
 100%     81 (longest request)
```

### 48

```
Concurrency Level:      48
Time taken for tests:   60.987 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1639.70 [#/sec] (mean)
Time per request:       29.274 [ms] (mean)
Time per request:       0.610 [ms] (mean, across all concurrent requests)
Transfer rate:          137.71 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   18  10.4     18      86
Processing:     0   11   8.0     11      76
Waiting:        0   10   7.9      9      73
Total:          2   29  16.4     30     108

Percentage of the requests served within a certain time (ms)
  50%     30
  66%     39
  75%     43
  80%     45
  90%     48
  95%     50
  98%     61
  99%     71
 100%    108 (longest request)
```

### 64

```
Concurrency Level:      64
Time taken for tests:   58.403 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1712.25 [#/sec] (mean)
Time per request:       37.378 [ms] (mean)
Time per request:       0.584 [ms] (mean, across all concurrent requests)
Transfer rate:          143.80 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   23  13.2     22      98
Processing:     0   14  10.1     13      78
Waiting:        0   13  10.0     11      76
Total:          2   37  20.9     37     126

Percentage of the requests served within a certain time (ms)
  50%     37
  66%     49
  75%     56
  80%     59
  90%     64
  95%     66
  98%     76
  99%     86
 100%    126 (longest request)
```

### 80

```
Concurrency Level:      80
Time taken for tests:   59.467 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1681.61 [#/sec] (mean)
Time per request:       47.573 [ms] (mean)
Time per request:       0.595 [ms] (mean, across all concurrent requests)
Transfer rate:          141.23 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   29  16.3     29     107
Processing:     0   18  12.5     18      74
Waiting:        0   16  12.3     15      73
Total:          2   47  26.1     50     137

Percentage of the requests served within a certain time (ms)
  50%     50
  66%     64
  75%     71
  80%     75
  90%     79
  95%     82
  98%     88
  99%     97
 100%    137 (longest request)
```

### 96

```
Concurrency Level:      96
Time taken for tests:   58.305 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1715.12 [#/sec] (mean)
Time per request:       55.973 [ms] (mean)
Time per request:       0.583 [ms] (mean, across all concurrent requests)
Transfer rate:          144.04 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   34  19.4     34     126
Processing:     0   22  15.1     20     113
Waiting:        0   19  15.0     17     112
Total:          2   56  31.4     57     159

Percentage of the requests served within a certain time (ms)
  50%     57
  66%     76
  75%     84
  80%     89
  90%     95
  95%     99
  98%    108
  99%    119
 100%    159 (longest request)
```

### 112

```
Concurrency Level:      112
Time taken for tests:   57.972 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1724.96 [#/sec] (mean)
Time per request:       64.929 [ms] (mean)
Time per request:       0.580 [ms] (mean, across all concurrent requests)
Transfer rate:          144.87 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   40  22.0     39     128
Processing:     0   25  17.1     24     101
Waiting:        0   22  17.0     20      98
Total:          2   65  35.7     67     178

Percentage of the requests served within a certain time (ms)
  50%     67
  66%     88
  75%     97
  80%    102
  90%    111
  95%    114
  98%    121
  99%    129
 100%    178 (longest request)
```

### 128

```
Concurrency Level:      128
Time taken for tests:   56.281 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1776.80 [#/sec] (mean)
Time per request:       72.040 [ms] (mean)
Time per request:       0.563 [ms] (mean, across all concurrent requests)
Transfer rate:          149.22 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   44  24.3     43     148
Processing:     0   28  19.0     26     110
Waiting:        0   24  18.8     22     108
Total:          2   72  39.6     72     190

Percentage of the requests served within a certain time (ms)
  50%     72
  66%     95
  75%    107
  80%    113
  90%    125
  95%    130
  98%    136
  99%    143
 100%    190 (longest request)
```

### 144

```
Concurrency Level:      144
Time taken for tests:   55.088 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1815.28 [#/sec] (mean)
Time per request:       79.327 [ms] (mean)
Time per request:       0.551 [ms] (mean, across all concurrent requests)
Transfer rate:          152.46 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   48  25.7     47     160
Processing:     0   31  20.6     29     132
Waiting:        0   26  20.6     23     130
Total:          2   79  42.1     77     217

Percentage of the requests served within a certain time (ms)
  50%     77
  66%    100
  75%    114
  80%    122
  90%    139
  95%    146
  98%    154
  99%    162
 100%    217 (longest request)
```

### 160

```
Concurrency Level:      160
Time taken for tests:   57.135 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1750.24 [#/sec] (mean)
Time per request:       91.416 [ms] (mean)
Time per request:       0.571 [ms] (mean, across all concurrent requests)
Transfer rate:          146.99 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   56  30.8     55     165
Processing:     0   36  24.3     34     148
Waiting:        0   31  24.1     28     147
Total:          2   91  50.4     93     248

Percentage of the requests served within a certain time (ms)
  50%     93
  66%    122
  75%    137
  80%    144
  90%    157
  95%    162
  98%    173
  99%    180
 100%    248 (longest request)
```

### 176

```
Concurrency Level:      176
Time taken for tests:   56.379 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1773.70 [#/sec] (mean)
Time per request:       99.227 [ms] (mean)
Time per request:       0.564 [ms] (mean, across all concurrent requests)
Transfer rate:          148.96 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   60  32.6     59     192
Processing:     0   39  26.1     37     141
Waiting:        0   34  26.1     30     137
Total:          2   99  54.1     98     271

Percentage of the requests served within a certain time (ms)
  50%     98
  66%    131
  75%    147
  80%    156
  90%    171
  95%    178
  98%    189
  99%    198
 100%    271 (longest request)
```

### 192

```
Concurrency Level:      192
Time taken for tests:   55.179 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      8600000 bytes
HTML transferred:       1100000 bytes
Requests per second:    1812.29 [#/sec] (mean)
Time per request:       105.943 [ms] (mean)
Time per request:       0.552 [ms] (mean, across all concurrent requests)
Transfer rate:          152.20 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2   64  34.3     63     192
Processing:     0   42  27.8     40     159
Waiting:        0   36  27.8     32     159
Total:          2  106  56.9    107     259

Percentage of the requests served within a certain time (ms)
  50%    107
  66%    139
  75%    154
  80%    164
  90%    183
  95%    191
  98%    202
  99%    209
 100%    259 (longest request)
```

## NGINX 1.3.6 (with `echo "hello world"`)

### 16

```
Concurrency Level:      16
Time taken for tests:   47.110 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2122.69 [#/sec] (mean)
Time per request:       7.538 [ms] (mean)
Time per request:       0.471 [ms] (mean, across all concurrent requests)
Transfer rate:          306.80 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1    6   2.1      5      30
Processing:     0    2   1.3      2      24
Waiting:        0    2   1.3      1      24
Total:          1    7   2.1      7      36

Percentage of the requests served within a certain time (ms)
  50%      7
  66%      8
  75%      9
  80%      9
  90%     10
  95%     11
  98%     12
  99%     13
 100%     36 (longest request)
```

### 32

```
Concurrency Level:      32
Time taken for tests:   41.726 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2396.58 [#/sec] (mean)
Time per request:       13.352 [ms] (mean)
Time per request:       0.417 [ms] (mean, across all concurrent requests)
Transfer rate:          346.38 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   10   3.4      9      56
Processing:     0    4   2.5      3      52
Waiting:        0    3   2.5      3      51
Total:          2   13   3.8     13      64

Percentage of the requests served within a certain time (ms)
  50%     13
  66%     15
  75%     15
  80%     16
  90%     18
  95%     19
  98%     22
  99%     23
```

### 48

```
Concurrency Level:      48
Time taken for tests:   41.083 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2434.09 [#/sec] (mean)
Time per request:       19.720 [ms] (mean)
Time per request:       0.411 [ms] (mean, across all concurrent requests)
Transfer rate:          351.80 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   14   5.0     13      55
Processing:     0    6   3.9      5      40
Waiting:        0    5   3.9      4      39
Total:          2   20   5.6     20      64

Percentage of the requests served within a certain time (ms)
  50%     20
  66%     22
  75%     23
  80%     24
  90%     27
  95%     29
  98%     33
  99%     35
 100%     64 (longest request)
```

### 64

```
Concurrency Level:      64
Time taken for tests:   40.752 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2453.84 [#/sec] (mean)
Time per request:       26.082 [ms] (mean)
Time per request:       0.408 [ms] (mean, across all concurrent requests)
Transfer rate:          354.66 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   18   6.6     17      68
Processing:     0    8   5.1      7      50
Waiting:        0    7   5.1      5      50
Total:          2   26   7.5     26      79

Percentage of the requests served within a certain time (ms)
  50%     26
  66%     29
  75%     30
  80%     32
  90%     35
  95%     38
  98%     43
  99%     47
 100%     79 (longest request)
```

### 80

```
Concurrency Level:      80
Time taken for tests:   40.885 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2445.88 [#/sec] (mean)
Time per request:       32.708 [ms] (mean)
Time per request:       0.409 [ms] (mean, across all concurrent requests)
Transfer rate:          353.51 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   23   8.6     22      91
Processing:     0   10   6.6      9      68
Waiting:        0    8   6.5      7      68
Total:          2   33   9.7     33     100

Percentage of the requests served within a certain time (ms)
  50%     33
  66%     36
  75%     38
  80%     40
  90%     44
  95%     49
  98%     56
  99%     59
 100%    100 (longest request)
```

### 96

```
Concurrency Level:      96
Time taken for tests:   40.734 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2454.93 [#/sec] (mean)
Time per request:       39.105 [ms] (mean)
Time per request:       0.407 [ms] (mean, across all concurrent requests)
Transfer rate:          354.81 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   27  10.4     26     107
Processing:     0   12   8.1     11      67
Waiting:        0   10   8.0      8      61
Total:          2   39  12.2     39     117

Percentage of the requests served within a certain time (ms)
  50%     39
  66%     43
  75%     46
  80%     48
  90%     54
  95%     60
  98%     67
  99%     72
 100%    117 (longest request)
```

### 112

```
Concurrency Level:      112
Time taken for tests:   41.334 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2419.33 [#/sec] (mean)
Time per request:       46.294 [ms] (mean)
Time per request:       0.413 [ms] (mean, across all concurrent requests)
Transfer rate:          349.67 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   31  12.5     30     134
Processing:     0   15   9.7     13      88
Waiting:        0   12   9.7     10      85
Total:          1   46  14.7     46     144

Percentage of the requests served within a certain time (ms)
  50%     46
  66%     51
  75%     55
  80%     57
  90%     65
  95%     73
  98%     79
  99%     85
 100%    144 (longest request)
```

### 128

```
Concurrency Level:      128
Time taken for tests:   41.395 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2415.73 [#/sec] (mean)
Time per request:       52.986 [ms] (mean)
Time per request:       0.414 [ms] (mean, across all concurrent requests)
Transfer rate:          349.15 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   36  14.4     34     140
Processing:     0   17  11.5     15     120
Waiting:        0   14  11.4     12     110
Total:          1   53  17.5     52     170

Percentage of the requests served within a certain time (ms)
  50%     52
  66%     58
  75%     62
  80%     65
  90%     75
  95%     84
  98%     94
  99%     99
 100%    170 (longest request)
```

### 144

```
Concurrency Level:      144
Time taken for tests:   41.529 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2407.97 [#/sec] (mean)
Time per request:       59.801 [ms] (mean)
Time per request:       0.415 [ms] (mean, across all concurrent requests)
Transfer rate:          348.03 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   40  29.9     38    3040
Processing:     0   20  13.0     18     133
Waiting:        0   16  13.0     14     128
Total:          1   60  32.2     59    3062

Percentage of the requests served within a certain time (ms)
  50%     59
  66%     66
  75%     71
  80%     75
  90%     85
  95%     94
  98%    105
  99%    115
 100%   3062 (longest request)
```

### 160

```
Concurrency Level:      160
Time taken for tests:   41.455 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2412.24 [#/sec] (mean)
Time per request:       66.328 [ms] (mean)
Time per request:       0.415 [ms] (mean, across all concurrent requests)
Transfer rate:          348.64 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   45  80.6     41    3082
Processing:     0   21  13.9     18     140
Waiting:        0   17  13.8     14     135
Total:          2   66  81.5     63    3088

Percentage of the requests served within a certain time (ms)
  50%     63
  66%     71
  75%     77
  80%     80
  90%     91
  95%    102
  98%    116
  99%    124
 100%   3088 (longest request)
```

### 176

```
Concurrency Level:      176
Time taken for tests:   41.501 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2409.60 [#/sec] (mean)
Time per request:       73.041 [ms] (mean)
Time per request:       0.415 [ms] (mean, across all concurrent requests)
Transfer rate:          348.26 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   49  84.4     45    3069
Processing:     0   24  15.3     21     160
Waiting:        0   19  15.2     16     154
Total:          1   73  85.3     70    3106

Percentage of the requests served within a certain time (ms)
  50%     70
  66%     78
  75%     84
  80%     89
  90%    101
  95%    113
  98%    129
  99%    137
 100%   3106 (longest request)
```

### 192

```
Concurrency Level:      192
Time taken for tests:   41.845 seconds
Complete requests:      100000
Failed requests:        0
Write errors:           0
Total transferred:      14800000 bytes
HTML transferred:       1200000 bytes
Requests per second:    2389.76 [#/sec] (mean)
Time per request:       80.343 [ms] (mean)
Time per request:       0.418 [ms] (mean, across all concurrent requests)
Transfer rate:          345.39 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1   55 125.2     48    3083
Processing:     0   25  16.6     22     172
Waiting:        0   20  16.4     17     172
Total:          2   80 126.3     74    3110

Percentage of the requests served within a certain time (ms)
  50%     74
  66%     84
  75%     91
  80%     96
  90%    109
  95%    123
  98%    141
  99%    153
 100%   3110 (longest request)
```

With patches

```
Time taken for tests:   90.921 seconds

Mutex block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
14820    75059 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   728 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@                     |  2074 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  3352 node`int_thread_get+0x26
     65536 |@@@@@@@@@               |  6076 node`int_thread_get_item+0x1f
    131072 |@@@                     |  2090 node`ERR_get_state+0x47
    262144 |                        |   306 
    524288 |                        |   103 
   1048576 |                        |    53 
   2097152 |                        |    28 
   4194304 |                        |    10 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
15545    57723 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   941 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |  1873 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  4262 node`def_get_class+0x4f
     65536 |@@@@@@@@@@              |  6727 node`int_new_ex_data+0x1d
    131072 |@@                      |  1610 node`BIO_set+0x86
    262144 |                        |    87 
    524288 |                        |    23 
   1048576 |                        |    13 
   2097152 |                        |     9 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
16307    46083 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@                  |  4488 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   843 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |  3600 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@               |  6265 node`def_get_class+0x4f
    131072 |@                       |  1027 node`int_new_ex_data+0x1d
    262144 |                        |    56 
    524288 |                        |    20 
   1048576 |                        |     6 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9567    75249 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    38 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   327 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |  1387 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@@@          |  5957 node`BIO_set+0x86
    131072 |@@@@                    |  1738 node`BIO_new+0x5f
    262144 |                        |    77 
    524288 |                        |    34 
   1048576 |                        |     6 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9150    72906 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    32 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   468 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |  2976 node`int_thread_get+0xa0
     65536 |@@@@@@@@@@@             |  4206 node`int_thread_get_item+0x1f
    131072 |@@@                     |  1252 node`ERR_get_state+0x47
    262144 |                        |   131 
    524288 |                        |    45 
   1048576 |                        |    29 
   2097152 |                        |     6 
   4194304 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9806    65779 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   445 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |  1173 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  2391 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  4740 node`int_free_ex_data+0x1d
    131072 |@@                      |   855 node`BIO_free+0x76
    262144 |                        |   116 
    524288 |                        |    43 
   1048576 |                        |    27 
   2097152 |                        |    13 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8804    67401 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   415 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |   713 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  1933 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  4400 node`int_new_ex_data+0x1d
    131072 |@@@                     |  1191 node`SSL_new+0x31f
    262144 |                        |   103 
    524288 |                        |    29 
   1048576 |                        |    15 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9290    56994 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   126 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |  1036 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  2887 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  4333 node`int_new_ex_data+0x4d
    131072 |@@                      |   858 node`BIO_set+0x86
    262144 |                        |    40 
    524288 |                        |     7 
   1048576 |                        |     2 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5784    81377 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    19 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   303 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |  1588 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@@            |  2958 node`int_free_ex_data+0x1d
    131072 |@@                      |   712 node`BIO_free+0x76
    262144 |                        |    98 
    524288 |                        |    52 
   1048576 |                        |    42 
   2097152 |                        |    10 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5923    76680 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    24 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   213 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |   956 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@@@          |  3526 node`SSL_new+0x31f
    131072 |@@@@                    |  1109 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    262144 |                        |    67 
    524288 |                        |    18 
   1048576 |                        |     7 
   2097152 |                        |     2 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7634    58290 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    38 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   523 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |  3071 node`def_get_class+0xd5
     65536 |@@@@@@@@@@              |  3323 node`int_new_ex_data+0x1d
    131072 |@                       |   602 node`BIO_set+0x86
    262144 |                        |    50 
    524288 |                        |    13 
   1048576 |                        |    10 
   2097152 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8938    47769 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |  2198 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   475 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |  2107 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@               |  3580 node`def_get_class+0x4f
    131072 |@                       |   516 node`int_free_ex_data+0x1d
    262144 |                        |    42 
    524288 |                        |    10 
   1048576 |                        |     7 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7907    53475 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   893 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   797 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  2104 node`def_get_class+0x4f
     65536 |@@@@@@@@@@              |  3417 node`int_new_ex_data+0x1d
    131072 |@                       |   642 node`SSL_SESSION_new+0xf7
    262144 |                        |    33 
    524288 |                        |    12 
   1048576 |                        |     8 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7695    54635 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   785 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   814 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  2053 node`def_get_class+0x4f
     65536 |@@@@@@@@@@              |  3371 node`int_free_ex_data+0x1d
    131072 |@                       |   608 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    43 
    524288 |                        |    11 
   1048576 |                        |     5 
   2097152 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6159    67702 0x1020088d0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    99 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   627 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  1595 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2876 node`int_thread_get_item+0x46
    131072 |@@@                     |   842 node`ERR_get_state+0x47
    262144 |                        |    83 
    524288 |                        |    21 
   1048576 |                        |    11 
   2097152 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5381    76002 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    19 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   182 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |   715 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@@@@@         |  3531 node`BIO_free+0x76
    131072 |@@@                     |   876 node`ssl3_digest_cached_records+0x186
    262144 |                        |    36 
    524288 |                        |     9 
   1048576 |                        |     7 
   2097152 |                        |     5 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7645    53340 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   815 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   862 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  1962 node`def_get_class+0x4f
     65536 |@@@@@@@@@@              |  3350 node`int_new_ex_data+0x1d
    131072 |@                       |   599 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    44 
    524288 |                        |     7 
   1048576 |                        |     5 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4519    89432 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    40 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   309 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@@                  |  1187 node`int_thread_get_item+0x70
     65536 |@@@@@@@@@               |  1797 node`ERR_get_state+0x47
    131072 |@@@@@                   |   951 node`get_error_values+0x33
    262144 |                        |   158 
    524288 |                        |    41 
   1048576 |                        |    22 
   2097152 |                        |    13 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6526    59171 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    70 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   742 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  2078 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  3005 node`int_free_ex_data+0x44
    131072 |@@                      |   571 node`BIO_free+0x76
    262144 |                        |    40 
    524288 |                        |    10 
   1048576 |                        |     5 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5202    72718 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    57 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   258 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |   777 node`int_free_ex_data+0xb9
     65536 |@@@@@@@@@@@@@@          |  3248 node`X509_STORE_CTX_cleanup+0x96
    131072 |@@@                     |   808 node`ssl3_output_cert_chain+0x15f
    262144 |                        |    34 
    524288 |                        |     9 
   1048576 |                        |     9 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6226    59418 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    85 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   613 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  1910 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2972 node`int_new_ex_data+0x4d
    131072 |@@                      |   597 node`SSL_new+0x31f
    262144 |                        |    34 
    524288 |                        |     6 
   1048576 |                        |     7 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4935    74602 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    22 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   174 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |   703 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@@@@         |  3120 node`SSL_SESSION_new+0xf7
    131072 |@@@@                    |   862 node`ssl_get_new_session+0x33
    262144 |                        |    40 
    524288 |                        |     5 
   1048576 |                        |     7 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4875    74489 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    32 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   252 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@                   |  1218 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@@            |  2469 node`int_new_ex_data+0x1d
    131072 |@@@@                    |   818 node`SSL_new+0x31f
    262144 |                        |    50 
    524288 |                        |    20 
   1048576 |                        |    13 
   2097152 |                        |     2 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4869    74242 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    33 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   227 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@                    |   846 node`int_new_ex_data+0xc2
     65536 |@@@@@@@@@@@@@@          |  2906 node`X509_STORE_CTX_init+0x2ca
    131072 |@@@                     |   777 node`ssl3_output_cert_chain+0xcd
    262144 |                        |    57 
    524288 |                        |    13 
   1048576 |                        |     5 
   2097152 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4135    84463 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    40 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   223 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@                   |   925 node`int_thread_get_item+0x70
     65536 |@@@@@@@@@@              |  1886 node`ERR_get_state+0x47
    131072 |@@@@@                   |   908 node`ERR_clear_error+0xc
    262144 |                        |    96 
    524288 |                        |    38 
   1048576 |                        |    12 
   2097152 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5509    62558 0x1020088d0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@                    |   922 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   258 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |  1222 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  2512 node`int_thread_get+0x26
    131072 |@@                      |   506 node`int_thread_get_item+0x1f
    262144 |                        |    52 
    524288 |                        |    12 
   1048576 |                        |    16 
   2097152 |                        |     6 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4647    71145 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   418 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |   232 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  1035 node`ssleay_rand_add+0xcb
     65536 |@@@@@@@@@@              |  2123 node`ssl23_accept+0x2f
    131072 |@@@                     |   721 node`ssl23_read+0x4e
    262144 |                        |    77 
    524288 |                        |    26 
   1048576 |                        |    11 
   2097152 |                        |     3 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4379    69982 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    17 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   200 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |  1254 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@@@@             |  2125 node`ssl23_accept+0x2f
    131072 |@@@                     |   718 node`ssl23_read+0x4e
    262144 |                        |    45 
    524288 |                        |    12 
   1048576 |                        |     6 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4775    55832 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    70 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   547 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  1507 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2229 node`int_new_ex_data+0x4d
    131072 |@@                      |   400 node`SSL_SESSION_new+0xf7
    262144 |                        |    15 
    524288 |                        |     4 
   1048576 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4646    55094 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    66 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   528 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  1535 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2152 node`int_free_ex_data+0x44
    131072 |@                       |   347 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    12 
    524288 |                        |     3 
   1048576 |                        |     1 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4532    54419 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   524 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   219 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@@                 |  1422 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1960 node`ssleay_rand_bytes+0x7a
    131072 |@                       |   366 node`ssleay_rand_pseudo_bytes+0xe
    262144 |                        |    32 
    524288 |                        |     6 
   1048576 |                        |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4233    54359 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    73 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   522 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@                 |  1351 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  1942 node`int_new_ex_data+0x4d
    131072 |@                       |   327 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    15 
    524288 |                        |     1 
   1048576 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3804    60227 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    25 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   217 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1619 node`def_get_class+0xd5
     65536 |@@@@@@@@@@              |  1587 node`int_new_ex_data+0x1d
    131072 |@@                      |   319 node`SSL_SESSION_new+0xf7
    262144 |                        |    15 
    524288 |                        |    11 
   1048576 |                        |     8 
   2097152 |                        |     2 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3645    57047 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    35 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   216 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1637 node`def_get_class+0xd5
     65536 |@@@@@@@@@               |  1472 node`int_new_ex_data+0x1d
    131072 |@                       |   250 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    15 
    524288 |                        |     9 
   1048576 |                        |    10 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3605    57064 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    28 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   222 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1558 node`def_get_class+0xd5
     65536 |@@@@@@@@@@              |  1505 node`int_free_ex_data+0x1d
    131072 |@                       |   262 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    14 
    524288 |                        |     7 
   1048576 |                        |     8 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3741    52995 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   441 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   176 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@@                 |  1208 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1568 node`ssleay_rand_bytes+0x40a
    131072 |@@                      |   327 node`ssleay_rand_pseudo_bytes+0xe
    262144 |                        |    17 
    524288 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3683    48756 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   212 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@@                  |  1016 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |  1295 node`ssleay_rand_bytes+0x452
     65536 |@@@@@                   |   882 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   215 node`ssl3_get_client_hello+0x56d
    262144 |                        |    35 
    524288 |                        |    15 
   1048576 |                        |    11 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3562    49823 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   156 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@@                  |   972 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |  1233 node`ssleay_rand_bytes+0x452
     65536 |@@@@@@                  |   907 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   233 node`def_generate_session_id+0x28
    262144 |                        |    36 
    524288 |                        |    17 
   1048576 |                        |     5 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3687    47909 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   121 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |   763 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |  1433 node`ssleay_rand_bytes+0x235
     65536 |@@@@@@@                 |  1127 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   211 node`ssl3_get_client_hello+0x56d
    262144 |                        |    20 
    524288 |                        |     6 
   1048576 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3118    56293 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    16 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |   371 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1311 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@                |  1104 node`ssl3_accept+0x31
    131072 |@@                      |   282 node`ssl23_get_client_hello+0x660
    262144 |                        |    21 
    524288 |                        |    10 
   1048576 |                        |     2 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3496    49505 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   185 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   417 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@@             |  1613 node`int_new_ex_data+0x4d
     65536 |@@@@@@@                 |  1045 node`BIO_set+0x86
    131072 |@                       |   199 node`BIO_new+0x5f
    262144 |                        |    22 
    524288 |                        |    10 
   1048576 |                        |     4 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2950    55433 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   106 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   406 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |  1247 node`int_thread_get_item+0x46
     65536 |@@@@@@@                 |   957 node`ERR_get_state+0x47
    131072 |@                       |   182 node`get_error_values+0x33
    262144 |                        |    29 
    524288 |                        |    12 
   1048576 |                        |     8 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3346    48684 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   107 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@                   |   817 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |  1168 node`ssleay_rand_bytes+0x235
     65536 |@@@@@@@                 |   978 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   245 node`def_generate_session_id+0x28
    262144 |                        |    18 
    524288 |                        |    10 
   1048576 |                        |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2088    74077 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   157 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@                     |   262 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |   508 node`def_get_class+0x4f
     65536 |@@@@@@@@@@              |   881 node`int_free_ex_data+0x1d
    131072 |@@                      |   222 node`SSL_free+0x65
    262144 |                        |    30 
    524288 |                        |    12 
   1048576 |                        |     6 
   2097152 |                        |     8 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1373   112020 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     5 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    71 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@                   |   303 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@              |   611 node`BIO_free+0x76
    131072 |@@@@                    |   279 node`ssl_free_wbio_buffer+0x2d
    262144 |                        |    52 
    524288 |                        |    26 
   1048576 |                        |    17 
   2097152 |                        |     8 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3590    42737 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@                  |  1005 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@                     |   474 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   910 node`ssleay_rand_add+0xcb
     65536 |@@@@@@                  |   950 node`ssl3_accept+0x31
    131072 |@                       |   224 node`ssl23_get_client_hello+0x660
    262144 |                        |    15 
    524288 |                        |     3 
   1048576 |                        |     8 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2233    66302 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   213 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   104 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |   605 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1000 node`ssleay_rand_add+0xcb
    131072 |@@                      |   266 node`ssl3_accept+0x31
    262144 |                        |    25 
    524288 |                        |    12 
   1048576 |                        |     5 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3765    39273 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   396 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |  1251 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  1084 node`ssleay_rand_bytes+0x7a
     65536 |@@@@@                   |   838 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   177 node`def_generate_session_id+0x28
    262144 |                        |    12 
    524288 |                        |     2 
   1048576 |                        |     4 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2883    50893 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    33 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |   511 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1234 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@@                 |   864 node`ssl23_accept+0x2f
    131072 |@                       |   217 node`ssl23_read+0x4e
    262144 |                        |    12 
    524288 |                        |     6 
   1048576 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3376    42498 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   254 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |  1058 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |  1026 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |   826 node`ssl23_accept+0x2f
    131072 |@                       |   187 node`ssl23_read+0x4e
    262144 |                        |    15 
    524288 |                        |     5 
   1048576 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  787   181650 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    13 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@@@                 |   246 node`BN_MONT_CTX_set_locked+0xe2
     65536 |@@@@@@@@@               |   319 node`RSA_eay_mod_exp+0x157
    131072 |@@@                     |   104 node`RSA_eay_private_decrypt+0x22e
    262144 |                        |    32 
    524288 |                        |    17 
   1048576 |                        |    31 
   2097152 |                        |    24 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  817   174348 0x102008f10                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |                        |    22 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@                  |   217 node`BN_MONT_CTX_set_locked+0x3e
     65536 |@@@@@@@@@@              |   349 node`RSA_eay_mod_exp+0x157
    131072 |@@@                     |   107 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    36 
    524288 |                        |    33 
   1048576 |                        |    30 
   2097152 |                        |    19 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4075    34717 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@                  |  1070 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@                  |  1092 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  1006 node`ssleay_rand_bytes+0x7a
     65536 |@@@@                    |   697 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   192 node`ssl3_get_client_hello+0x56d
    262144 |                        |    12 
    524288 |                        |     3 
   1048576 |                        |     0 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2314    60190 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   236 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   105 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@@                 |   681 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1027 node`ssleay_rand_add+0x367
    131072 |@@                      |   239 node`ssl3_accept+0x31
    262144 |                        |    20 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2235    61995 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   206 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |    98 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |   620 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1008 node`ssleay_rand_add+0x367
    131072 |@@                      |   277 node`ssl23_accept+0x2f
    262144 |                        |    20 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  791   174890 0x102008f10                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |                        |    23 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@                 |   260 node`BN_MONT_CTX_set_locked+0x3e
     65536 |@@@@@@@@@               |   307 node`RSA_eay_mod_exp+0x17c
    131072 |@@                      |    96 node`RSA_eay_private_decrypt+0x22e
    262144 |                        |    25 
    524288 |                        |    26 
   1048576 |@                       |    33 
   2097152 |                        |    20 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  559   241290 0x102008f10                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     5 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@                       |    26 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@                   |   118 node`rsa_get_blinding+0x41
     65536 |@@@@@@@@                |   202 node`RSA_eay_private_decrypt+0x179
    131072 |@@@                     |    73 node`ssl3_get_client_key_exchange+0x159
    262144 |@                       |    43 
    524288 |@                       |    38 
   1048576 |@                       |    35 
   2097152 |                        |    19 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  760   176408 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    22 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@@@                 |   236 node`BN_MONT_CTX_set_locked+0xe2
     65536 |@@@@@@@@@               |   294 node`RSA_eay_mod_exp+0x17c
    131072 |@@                      |    90 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    34 
    524288 |                        |    26 
   1048576 |@                       |    43 
   2097152 |                        |    13 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3342    37739 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   192 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@@               |  1334 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |   980 node`ssleay_rand_bytes+0x40a
     65536 |@@@@                    |   637 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   188 node`ssl3_get_client_hello+0x56d
    262144 |                        |     8 
    524288 |                        |     2 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2564    48653 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    38 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |   493 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |  1133 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@                  |   709 node`ssl3_accept+0x31
    131072 |@                       |   168 node`ssl23_get_client_hello+0x660
    262144 |                        |    15 
    524288 |                        |     5 
   1048576 |                        |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3266    38158 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   247 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@@               |  1291 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   920 node`ssleay_rand_bytes+0x40a
     65536 |@@@@                    |   628 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |   164 node`def_generate_session_id+0x28
    262144 |                        |     7 
    524288 |                        |     7 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1783    65935 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   165 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |    79 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |   413 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@             |   847 node`ssleay_rand_add+0xcb
    131072 |@@@                     |   242 node`ssl23_accept+0x2f
    262144 |                        |    30 
    524288 |                        |     2 
   1048576 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3114    37655 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   254 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@                |  1054 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |   948 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |   720 node`ssl3_accept+0x31
    131072 |@                       |   130 node`ssl23_get_client_hello+0x660
    262144 |                        |     6 
    524288 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1122   104028 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    78 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   115 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |   219 node`ssleay_rand_add+0xcb
     65536 |@@@@@@@@@               |   435 node`ssl3_accept+0x31
    131072 |@@@@                    |   193 node`ssl3_read_bytes+0x17a
    262144 |                        |    43 
    524288 |                        |    18 
   1048576 |                        |    13 
   2097152 |                        |     7 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1977    58040 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    99 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   200 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@               |   749 node`int_new_ex_data+0x4d
     65536 |@@@@@@@@@               |   754 node`SSL_new+0x31f
    131072 |@                       |   148 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    262144 |                        |    14 
    524288 |                        |     6 
   1048576 |                        |     4 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2122    54074 0x1020088d0                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    93 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   251 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   949 node`int_thread_get_item+0x46
     65536 |@@@@@@@                 |   668 node`ERR_get_state+0x47
    131072 |@                       |   131 node`ERR_clear_error+0xc
    262144 |                        |    14 
    524288 |                        |    11 
   1048576 |                        |     4 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  803   132388 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     5 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    48 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@@                  |   227 node`BN_MONT_CTX_set_locked+0xe2
     65536 |@@@@@@@@@@              |   342 node`RSA_eay_mod_exp+0x137
    131072 |@@                      |    97 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    34 
    524288 |                        |    23 
   1048576 |                        |    16 
   2097152 |                        |    10 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1214    82527 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    72 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@                    |   236 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@@            |   652 node`SSL_free+0x65
    131072 |@@@@                    |   212 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    262144 |                        |    23 
    524288 |                        |     6 
   1048576 |                        |     3 
   2097152 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1268    77423 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    69 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |   382 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@             |   597 node`int_free_ex_data+0x1d
    131072 |@@@                     |   164 node`SSL_free+0x65
    262144 |                        |    31 
    524288 |                        |    12 
   1048576 |                        |     5 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1607    60096 0x102008998                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    49 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |   278 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |   478 node`def_get_class+0x4f
     65536 |@@@@@@@@@               |   613 node`int_free_ex_data+0x1d
    131072 |@@                      |   161 node`SSL_SESSION_free+0x54
    262144 |                        |    18 
    524288 |                        |     5 
   1048576 |                        |     3 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1027    91380 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    30 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |   300 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@@@              |   466 node`ssl3_accept+0x31
    131072 |@@@@                    |   178 node`ssl3_read_bytes+0x17a
    262144 |                        |    23 
    524288 |                        |    13 
   1048576 |                        |    10 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1046    86470 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     7 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    59 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@                    |   175 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@@            |   555 node`SSL_SESSION_free+0x54
    131072 |@@@@@                   |   221 node`SSL_free+0xfe
    262144 |                        |    16 
    524288 |                        |     5 
   1048576 |                        |     5 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  643   136626 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    47 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@                    |   126 node`rsa_get_blinding+0x18f
     65536 |@@@@@@@@@@@             |   299 node`RSA_eay_private_decrypt+0x179
    131072 |@@@                     |    83 node`ssl3_get_client_key_exchange+0x159
    262144 |@                       |    42 
    524288 |                        |    13 
   1048576 |                        |    21 
   2097152 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  695   121335 0x102008f10                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    10 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@                       |    50 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@                   |   166 node`BN_MONT_CTX_set_locked+0x3e
     65536 |@@@@@@@@@@              |   302 node`RSA_eay_mod_exp+0x137
    131072 |@@@                     |   100 node`RSA_eay_private_decrypt+0x22e
    262144 |                        |    26 
    524288 |                        |    23 
   1048576 |                        |    11 
   2097152 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1628    51064 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    84 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   172 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   738 node`int_new_ex_data+0x4d
     65536 |@@@@@@@                 |   514 node`X509_STORE_CTX_init+0x2ca
    131072 |@                       |   102 node`ssl3_output_cert_chain+0xcd
    262144 |                        |    12 
    524288 |                        |     2 
   1048576 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1566    51861 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    84 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   177 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   679 node`int_free_ex_data+0x44
     65536 |@@@@@@@@                |   533 node`BIO_free+0x76
    131072 |@                       |    78 node`ssl3_digest_cached_records+0x186
    262144 |                        |     7 
    524288 |                        |     2 
   1048576 |                        |     5 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1598    48449 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    85 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   175 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@@             |   746 node`int_new_ex_data+0x4d
     65536 |@@@@@@@                 |   498 node`SSL_SESSION_new+0xf7
    131072 |@                       |    84 node`ssl_get_new_session+0x33
    262144 |                        |     6 
    524288 |                        |     2 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  957    79394 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    27 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   128 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@                |   344 node`int_free_ex_data+0x44
     65536 |@@@@@@@@                |   328 node`BIO_free+0x76
    131072 |@@                      |    90 node`ssl_free_wbio_buffer+0x2d
    262144 |                        |    21 
    524288 |                        |     9 
   1048576 |                        |     6 
   2097152 |                        |     2 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1569    48133 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    87 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   162 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@@@            |   788 node`int_free_ex_data+0x44
     65536 |@@@@@@                  |   441 node`X509_STORE_CTX_cleanup+0x96
    131072 |@                       |    79 node`ssl3_output_cert_chain+0x15f
    262144 |                        |     7 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1143    62769 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    20 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   109 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |   314 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |   564 node`int_free_ex_data+0x44
    131072 |@@                      |   122 node`SSL_free+0x65
    262144 |                        |    11 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  975    67695 0x102008998                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     7 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    69 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |   414 node`def_get_class+0xd5
     65536 |@@@@@@@@                |   358 node`int_free_ex_data+0x1d
    131072 |@@                      |    94 node`SSL_SESSION_free+0x54
    262144 |                        |    17 
    524288 |                        |    11 
   1048576 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  796    56952 0x102008998                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    10 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |    86 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@@@                |   270 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@              |   350 node`int_free_ex_data+0x44
    131072 |@@                      |    74 node`SSL_SESSION_free+0x54
    262144 |                        |     5 
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  598    73508 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |    75 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@              |   263 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@                  |   166 node`ssl3_accept+0x31
    131072 |@@                      |    63 node`ssl3_read_bytes+0x17a
    262144 |                        |    11 
    524288 |                        |    11 
   1048576 |                        |     4 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  755    57799 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    39 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   224 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |   240 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |   175 node`ssl3_accept+0x31
    131072 |@                       |    57 node`ssl3_read_bytes+0x17a
    262144 |                        |     9 
    524288 |                        |     6 
   1048576 |                        |     3 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  577    65677 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    24 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |    73 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@               |   222 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   192 node`SSL_free+0x65
    131072 |@@                      |    49 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    262144 |                        |    11 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  543    52531 0x102008998                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    20 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |    59 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   246 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   175 node`SSL_SESSION_free+0x54
    131072 |@                       |    34 node`SSL_free+0xfe
    262144 |                        |     5 
    524288 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  138   180520 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     9 node`uv_mutex_lock+0x9
     16384 |@@@@@@                  |    40 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@@@                   |    32 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@@@                    |    23 node`uv__thread_start+0x22
    131072 |@@                      |    15 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |    11 
    524288 |                        |     2 
   1048576 |                        |     1 
   2097152 |                        |     3 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  104   213937 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     6 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@                |    35 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@@@@                  |    26 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@                      |     9 node`uv__thread_start+0x22
    131072 |@@@                     |    16 libSystem.B.dylib`_pthread_start+0x14b
    262144 |                        |     3 
    524288 |                        |     3 
   1048576 |                        |     1 
   2097152 |                        |     3 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  131   152896 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     5 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@              |    58 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@@                    |    27 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@@                     |    17 node`uv__thread_start+0x22
    131072 |@                       |     8 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |     9 
    524288 |                        |     4 
   1048576 |                        |     1 
   2097152 |                        |     1 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   20   684032 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@              |     9 node`uv_mutex_lock+0x9
     32768 |@@@                     |     3 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@                     |     3 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |@                       |     1 node`uv__async_io+0x98
    262144 |                        |     0 node`ev_invoke_pending+0x4f
    524288 |@                       |     1 
   1048576 |                        |     0 
   2097152 |@@                      |     2 
   4194304 |                        |     0 
   8388608 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  127    78888 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    11 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@                |    44 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@@@                   |    31 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@@                     |    17 node`uv__thread_start+0x22
    131072 |@                       |    10 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |     8 
    524288 |                        |     5 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  131    51215 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    13 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@           |    73 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@                   |    31 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |@                       |     7 0x2a208512def9
    131072 |                        |     4 0x2a2085123ea4
    262144 |                        |     1 
    524288 |                        |     0 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  124    52785 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    13 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@           |    69 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@                   |    26 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |@                       |     6 0x2a208512def9
    131072 |                        |     5 0x2a2085123ea4
    262144 |                        |     3 
    524288 |                        |     1 
   1048576 |                        |     0 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   46   135524 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 node`uv_mutex_lock+0x9
     16384 |@@@@@@                  |    12 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@                  |    12 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
     65536 |@@@@@@                  |    12 0x2a2085143f39
    131072 |@                       |     3 0x2a208511196d
    262144 |@                       |     3 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   33   171535 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     3 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@                |    12 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@@                 |    10 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@                       |     2 0x2a208512e739
    131072 |@                       |     2 0x2a2084ef489a
    262144 |@                       |     2 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |@                       |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   74    73838 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     3 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |     8 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |    30 node`ssleay_rand_bytes+0x452
     65536 |@@@@@                   |    18 node`bnrand+0xe0
    131072 |@@                      |     8 node`bn_rand_range+0x13c
    262144 |@                       |     6 
    524288 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   39   138003 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@           |    22 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@                  |    11 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
     65536 |@                       |     3 0x2a2085143f39
    131072 |                        |     0 0x2a208511196d
    262144 |                        |     1 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  146    32599 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    19 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@@          |    87 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@                    |    27 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |                        |     3 0x2a208512def9
    131072 |                        |     4 0x2a2085123ea4
    262144 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   60    77824 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@                  |    15 node`uv_mutex_lock+0x9
     32768 |@@@@@@@@@@@             |    29 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@                      |     7 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
    131072 |                        |     1 0x2a2085143f39
    262144 |@@                      |     7 0x2a208511196d
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  126    28021 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    13 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@           |    73 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@                  |    34 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |                        |     1 0x2a208512def9
    131072 |                        |     2 0x2a2085123ea4
    262144 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   33    91353 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     4 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |     2 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |     6 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |    14 node`ssleay_rand_add+0x367
    131072 |@@@@                    |     6 node`bnrand+0xbc
    262144 |                        |     0 
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   27   109226 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     2 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@               |    11 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@                       |     2 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@@@@                    |     5 0x2a208512e739
    131072 |@                       |     2 0x2a2084ef489a
    262144 |@                       |     2 
    524288 |@@                      |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   25   115998 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@                |     9 node`uv_mutex_lock+0x9
     32768 |@@@                     |     4 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@                   |     6 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |                        |     1 node`uv__async_io+0x98
    262144 |@@@                     |     4 node`ev_invoke_pending+0x4f
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   38    74159 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@                 |    12 node`uv_mutex_lock+0x9
     32768 |@@@@@@@                 |    12 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@@                  |    10 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
    131072 |@                       |     2 0x2a2085143f39
    262144 |                        |     1 0x2a208511196d
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   25    98959 0x1020090a0                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@                    |     5 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     32768 |                        |     1 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |     4 node`X509_STORE_get_by_subject+0x3d
    131072 |@@@@@@@@@@@@@           |    14 node`X509_STORE_CTX_get1_issuer+0x48
    262144 |                        |     1 node`X509_verify_cert+0x2a9
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   40    56524 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     4 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@@               |    16 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |    12 node`ssleay_rand_add+0x367
     65536 |@@@                     |     6 node`bnrand+0xbc
    131072 |                        |     1 node`bn_rand_range+0x13c
    262144 |                        |     0 
    524288 |                        |     0 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   51    39032 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@                  |    13 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |    11 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |    10 node`ssleay_rand_add+0xcb
     65536 |@@@@@@                  |    13 node`bnrand+0xbc
    131072 |@                       |     4 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   36    54158 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@@@                     |     5 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@@@              |    15 node`uv_rwlock_wrunlock+0x9
     65536 |@@@@@@@@                |    13 node`ssleay_rand_add+0x3d7
    131072 |@                       |     2 node`bnrand+0xbc
    262144 |                        |     1 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   36    53703 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@                       |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@@               |    14 node`uv_rwlock_wrunlock+0x9
     65536 |@@@@@@@@@@@@            |    18 node`ssleay_rand_add+0x1cf
    131072 |@                       |     2 node`bnrand+0xbc
                                            node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   28    58806 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     0 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |     6 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@@@@@@@       |    20 node`ssleay_rand_bytes+0x40a
    131072 |                        |     1 node`bnrand+0xe0
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   51    30679 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@                  |    13 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@                  |    13 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |    16 node`ssleay_rand_bytes+0x40a
     65536 |@@@                     |     7 node`bnrand+0xe0
    131072 |                        |     2 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   29    51411 0x102009618                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |     6 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |     8 node`ssleay_rand_bytes+0x235
     65536 |@@@@@@@                 |     9 node`bnrand+0xe0
    131072 |@@@                     |     4 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   28    51785 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     3 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |     7 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@@@           |    16 node`ssleay_rand_add+0xcb
    131072 |                        |     1 node`bnrand+0xbc
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   26    55768 0x1020090a0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |     4 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@@@             |    12 node`X509_STORE_get_by_subject+0x6c
     65536 |@@@@                    |     5 node`X509_STORE_CTX_get1_issuer+0x48
    131072 |@@                      |     3 node`X509_verify_cert+0x2a9
    262144 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   16    81920 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@                  |     4 node`uv_mutex_lock+0x9
     32768 |@@@@@@@@@               |     6 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@@                  |     4 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |                        |     0 node`uv__async_io+0x98
    262144 |@                       |     1 node`ev_invoke_pending+0x4f
    524288 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   29    44914 0x102009618                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |     5 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@@@@              |    13 node`ssleay_rand_bytes+0x7a
     65536 |@@@@@@                  |     8 node`bnrand+0xe0
    131072 |@                       |     2 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   17    46742 0x102009618                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@@                 |     5 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     0 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@@                 |     5 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |     5 node`ssleay_rand_bytes+0x7a
    131072 |@@                      |     2 node`bnrand+0xe0
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   16    48640 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     1 node`uv_mutex_lock+0x9
     16384 |@@@@@@@                 |     5 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@@                 |     5 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@@@                     |     2 0x2a208512e739
    131072 |@@@@                    |     3 0x2a2084ef489a
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   25    25231 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@             |    12 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@@@@@              |    11 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |                        |     1 0x2a208512e739
                                            0x2a2084ef489a
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    6    60074 0x1020090a0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@                |     2 libSystem.B.dylib`_pthread_cond_wait+0x586
     32768 |                        |     0 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     65536 |@@@@@@@@@@@@            |     3 node`uv_rwlock_wrlock+0x9
    131072 |@@@@                    |     1 node`X509_STORE_get_by_subject+0x3d
                                            node`X509_STORE_CTX_get1_issuer+0x48
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2   163840 0x102008f10                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@            |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
    131072 |                        |     0 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
    262144 |@@@@@@@@@@@@            |     1 node`uv_rwlock_rdlock+0x9
                                            node`rsa_get_blinding+0x41
                                            node`RSA_eay_private_decrypt+0x179
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    6    46421 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |     3 node`uv_mutex_lock+0x9
     32768 |@@@@                    |     1 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@                    |     1 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |@@@@                    |     1 node`uv__async_io+0x98
                                            node`ev_invoke_pending+0x4f
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    3    60074 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@                |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@                |     1 node`uv_rwlock_wrunlock+0x9
     65536 |                        |     0 node`BN_MONT_CTX_set_locked+0xe2
    131072 |@@@@@@@@                |     1 node`RSA_eay_mod_exp+0x157
                                            node`RSA_eay_private_decrypt+0x22e
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x102008f10                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
                                            node`uv_rwlock_wrlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x79
                                            node`RSA_eay_mod_exp+0x157
                                            node`RSA_eay_private_decrypt+0x22e
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x102008f10                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
                                            node`uv_rwlock_rdunlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x60
                                            node`RSA_eay_mod_exp+0x157
                                            node`RSA_eay_private_decrypt+0x22e
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x102008f10                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`_pthread_cond_wait+0x586
                                            libSystem.B.dylib`pthread_rwlock_wrlock+0x119
                                            node`uv_rwlock_wrlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x79
                                            node`RSA_eay_mod_exp+0x157
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a208501e6b9
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    40960 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |     1 node`uv_mutex_lock+0x9
     32768 |                        |     0 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@@@@@@@@            |     1 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x2a20850139b9
                                            0x2a208502b6ad
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    32768 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     2 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x2a2085071059
                                            0x2a208502b6ad
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    32768 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     2 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a2085053c79
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    32768 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a2085053c79
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    32768 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
                                            0x2a2085054d59
                                            0x2a2084ef489a
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    32768 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a208501e6b9
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x10181b1e8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
                                            0x2a2085054d59
                                            0x2a2084ef489a
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x2a20850139b9
                                            0x2a208502b6ad
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x2a2085071059
                                            0x2a208502b6ad
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101819338                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a2085053c79
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x2a2085071059
                                            0x2a208502b6ad
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101817eb8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a2085053c79
                                            0x2a2085047104
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x101815988                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x2a208501e6b9
                                            0x2a2085047104

R/W reader block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8979   572693 0x1020088c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   160 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1146 node`int_thread_get_item+0x46
    131072 |@@@@@@@@                |  3065 node`ERR_get_state+0x47
    262144 |@@@@@@                  |  2333 node`get_error_values+0x33
    524288 |@@                      |   964 node`SSL_get_error+0x24
   1048576 |@                       |   521 
   2097152 |@                       |   425 
   4194304 |                        |   264 
   8388608 |                        |    83 
  16777216 |                        |    18 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
11016   333043 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   137 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1393 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@              |  4720 node`SSL_new+0x31f
    262144 |@@@@@@@                 |  3454 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    524288 |@                       |   654 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x4b
   1048576 |                        |   287 
   2097152 |                        |   208 
   4194304 |                        |   109 
   8388608 |                        |    47 
  16777216 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8617   298882 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   105 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1244 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@              |  3873 node`BIO_set+0x86
    262144 |@@@@@@                  |  2510 node`BIO_new+0x5f
    524288 |@                       |   467 node`ssl3_init_finished_mac+0x51
   1048576 |                        |   180 
   2097152 |                        |   127 
   4194304 |                        |    77 
   8388608 |                        |    32 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8996   274521 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   158 node`uv_rwlock_rdlock+0x9
     65536 |@@@@                    |  1508 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@@@             |  4188 node`BIO_free+0x76
    262144 |@@@@@@                  |  2396 node`ssl3_digest_cached_records+0x186
    524288 |@                       |   397 node`ssl3_get_client_hello+0xa0d
   1048576 |                        |   133 
   2097152 |                        |   113 
   4194304 |                        |    68 
   8388608 |                        |    32 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8190   269161 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   146 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1338 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@@@             |  3873 node`X509_STORE_CTX_cleanup+0x96
    262144 |@@@@@@                  |  2138 node`ssl3_output_cert_chain+0x15f
    524288 |@                       |   391 node`ssl3_send_server_certificate+0x48
   1048576 |                        |   122 
   2097152 |                        |   101 
   4194304 |                        |    53 
   8388608 |                        |    23 
  16777216 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8295   263159 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   139 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1345 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@@             |  3803 node`SSL_SESSION_new+0xf7
    262144 |@@@@@@                  |  2318 node`ssl_get_new_session+0x33
    524288 |@                       |   379 node`ssl3_get_client_hello+0x23b
   1048576 |                        |   137 
   2097152 |                        |    90 
   4194304 |                        |    60 
   8388608 |                        |    24 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3011   723573 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    26 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   303 node`int_free_ex_data+0x44
    131072 |@@@@@@@                 |   934 node`BIO_free+0x76
    262144 |@@@@@@                  |   813 node`ssl_free_wbio_buffer+0x2d
    524288 |@@                      |   344 node`ssl3_accept+0xb53
   1048576 |@                       |   232 
   2097152 |@                       |   199 
   4194304 |                        |   104 
   8388608 |                        |    49 
  16777216 |                        |     6 
  33554432 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7792   277266 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   116 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1184 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@@             |  3642 node`BIO_set+0x86
    262144 |@@@@@@                  |  2200 node`BIO_new+0x5f
    524288 |@                       |   341 node`ssl_init_wbio_buffer+0x30
   1048576 |                        |   135 
   2097152 |                        |    78 
   4194304 |                        |    65 
   8388608 |                        |    30 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7585   280647 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   115 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |  1182 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@@             |  3557 node`X509_STORE_CTX_init+0x2ca
    262144 |@@@@@@                  |  2030 node`ssl3_output_cert_chain+0xcd
    524288 |@                       |   363 node`ssl3_send_server_certificate+0x48
   1048576 |                        |   145 
   2097152 |                        |   109 
   4194304 |                        |    62 
   8388608 |                        |    18 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3085   640330 0x1020088c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    47 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   397 node`int_thread_get_item+0x46
    131072 |@@@@@@@@                |  1039 node`ERR_get_state+0x47
    262144 |@@@@@                   |   733 node`ERR_clear_error+0xc
    524288 |@@                      |   367 node`ssl3_accept+0x36
   1048576 |@                       |   175 
   2097152 |@                       |   173 
   4194304 |                        |   106 
   8388608 |                        |    44 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2359   514370 0x1020088c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    28 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   283 node`int_thread_get_item+0x46
    131072 |@@@@@@@@                |   869 node`ERR_get_state+0x47
    262144 |@@@@@@                  |   634 node`ERR_clear_error+0xc
    524288 |@@                      |   253 node`ssl23_accept+0x34
   1048576 |@                       |   117 
   2097152 |                        |    84 
   4194304 |                        |    71 
   8388608 |                        |    18 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2480   451735 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    37 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   338 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@               |   939 node`SSL_free+0x65
    262144 |@@@@@@                  |   693 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    524288 |@                       |   203 tlsnappy.node`tlsnappy::Context::RunLoop()+0x8a
   1048576 |@                       |   122 
   2097152 |                        |    88 
   4194304 |                        |    37 
   8388608 |                        |    20 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2311   462481 0x1020088c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    45 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   318 node`int_thread_get_item+0x46
    131072 |@@@@@@@@                |   852 node`ERR_get_state+0x47
    262144 |@@@@@@                  |   614 node`ERR_clear_error+0xc
    524288 |@@                      |   238 node`ssl3_output_cert_chain+0x108
   1048576 |                        |    93 
   2097152 |                        |    83 
   4194304 |                        |    46 
   8388608 |                        |    22 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1776   372182 0x102008990                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    30 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   289 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@               |   715 node`SSL_SESSION_free+0x54
    262144 |@@@@@@                  |   454 node`SSL_free+0xfe
    524288 |@                       |   131 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
   1048576 |                        |    63 
   2097152 |                        |    64 
   4194304 |                        |    22 
   8388608 |                        |     8 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    4  4718592 0x102008f08                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
   2097152 |@@@@@@                  |     1 node`uv_rwlock_rdlock+0x9
   4194304 |@@@@@@@@@@@@            |     2 node`rsa_get_blinding+0x41
   8388608 |@@@@@@                  |     1 node`RSA_eay_private_decrypt+0x179
                                            node`ssl3_get_client_key_exchange+0x159
                                            node`ssl3_accept+0x83f
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1  2097152 0x102008f08                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
   2097152 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_rwlock_rdlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x3e
                                            node`RSA_eay_mod_exp+0x157
                                            node`RSA_eay_private_decrypt+0x22e
                                            node`ssl3_get_client_key_exchange+0x159
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1  1048576 0x102008f08                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
   1048576 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_rwlock_rdlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x3e
                                            node`RSA_eay_mod_exp+0x137
                                            node`RSA_eay_private_decrypt+0x22e
                                            node`ssl3_get_client_key_exchange+0x159

R/W writer block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
14290   110039 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |  1650 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |  4885 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@             |  7046 node`int_new_ex_data+0x1d
    262144 |                        |   578 node`BIO_set+0x86
    524288 |                        |    69 node`BIO_new+0x5f
   1048576 |                        |    43 
   2097152 |                        |    18 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5192   292021 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    88 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   431 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@@@@           |  2878 node`ssl23_accept+0x2f
    262144 |@@@@@                   |  1256 node`ssl23_read+0x4e
    524288 |@                       |   275 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x116
   1048576 |                        |   107 
   2097152 |                        |    93 
   4194304 |                        |    50 
   8388608 |                        |    14 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6043   242013 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |                        |   225 node`ssleay_rand_bytes+0x7a
     65536 |@@                      |   643 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@@@@@@@@@@@@@           |  3486 node`ssl3_get_client_hello+0x56d
    262144 |@@@@@                   |  1267 node`ssl3_accept+0x4a1
    524288 |                        |   208 
   1048576 |                        |    99 
   2097152 |                        |    74 
   4194304 |                        |    21 
   8388608 |                        |    18 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3976   354740 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |                        |    79 node`ssleay_rand_add+0xcb
     65536 |@                       |   316 node`ssl23_accept+0x2f
    131072 |@@@@@@@@@@@             |  1977 node`ssl23_read+0x4e
    262144 |@@@@@@                  |  1051 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x116
    524288 |@                       |   268 
   1048576 |                        |   115 
   2097152 |                        |   108 
   4194304 |                        |    37 
   8388608 |                        |    23 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4625   280982 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   107 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   466 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@@@@@          |  2721 node`ssl3_accept+0x31
    262144 |@@@@@                   |   977 node`ssl23_get_client_hello+0x660
    524288 |                        |   163 node`ssl23_accept+0x14f
   1048576 |                        |    79 
   2097152 |                        |    47 
   4194304 |                        |    46 
   8388608 |                        |    15 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5121   252910 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   125 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   454 node`ssleay_rand_bytes+0x7a
    131072 |@@@@@@@@@@@@@@          |  3087 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@@                   |  1086 node`def_generate_session_id+0x28
    524288 |                        |   191 node`ssl_get_new_session+0x18f
   1048576 |                        |    64 
   2097152 |                        |    65 
   4194304 |                        |    36 
   8388608 |                        |    12 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4568   270931 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    97 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   440 node`ssleay_rand_add+0xcb
    131072 |@@@@@@@@@@@@@           |  2546 node`ssl3_accept+0x31
    262144 |@@@@@                   |  1082 node`ssl23_get_client_hello+0x660
    524288 |@                       |   204 node`ssl23_accept+0x14f
   1048576 |                        |    93 
   2097152 |                        |    55 
   4194304 |                        |    38 
   8388608 |                        |    13 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4723   246977 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   148 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   519 node`ssleay_rand_bytes+0x40a
    131072 |@@@@@@@@@@@@@@          |  2765 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@                    |   955 node`ssl3_get_client_hello+0x56d
    524288 |                        |   162 node`ssl3_accept+0x4a1
   1048576 |                        |    70 
   2097152 |                        |    64 
   4194304 |                        |    29 
   8388608 |                        |    10 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4689   248443 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |                        |   145 node`ssleay_rand_bytes+0x40a
     65536 |@@                      |   479 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@@@@@@@@@@@@@           |  2724 node`def_generate_session_id+0x28
    262144 |@@@@@                   |  1016 node`ssl_get_new_session+0x18f
    524288 |                        |   166 
   1048576 |                        |    57 
   2097152 |                        |    61 
   4194304 |                        |    27 
   8388608 |                        |    12 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7481   139411 0x1020088c8                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   808 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |  2508 node`int_thread_get+0x26
    131072 |@@@@@@@@@@              |  3123 node`int_thread_get_item+0x1f
    262144 |@@                      |   785 node`ERR_get_state+0x47
    524288 |                        |   154 node`get_error_values+0x33
   1048576 |                        |    71 
   2097152 |                        |    27 
   4194304 |                        |     4 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7636   121019 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |   717 node`def_get_class+0x4f
     65536 |@@@@@@@                 |  2272 node`int_new_ex_data+0x1d
    131072 |@@@@@@@@@@@@            |  4031 node`SSL_new+0x31f
    262144 |@                       |   530 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    524288 |                        |    53 
   1048576 |                        |    22 
   2097152 |                        |     6 
   4194304 |                        |     3 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6962   131446 0x1020088c8                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |   677 node`int_thread_get+0x26
     65536 |@@@@@@@                 |  2269 node`int_thread_get_item+0x1f
    131072 |@@@@@@@@@@              |  3188 node`ERR_get_state+0x47
    262144 |@@                      |   661 node`ERR_clear_error+0xc
    524288 |                        |    92 
   1048576 |                        |    52 
   2097152 |                        |    20 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8053   107670 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   847 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |  2739 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  4074 node`int_new_ex_data+0x1d
    262144 |@                       |   356 node`SSL_SESSION_new+0xf7
    524288 |                        |    20 node`ssl_get_new_session+0x33
   1048576 |                        |    13 
   2097152 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8029   107262 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   836 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |  2761 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  4051 node`int_free_ex_data+0x1d
    262144 |@                       |   335 node`X509_STORE_CTX_cleanup+0x96
    524288 |                        |    33 node`ssl3_output_cert_chain+0x15f
   1048576 |                        |    10 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7300   111110 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   719 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |  2397 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  3788 node`int_free_ex_data+0x1d
    262144 |@                       |   343 node`BIO_free+0x76
    524288 |                        |    36 node`ssl3_digest_cached_records+0x186
   1048576 |                        |    10 
   2097152 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1014   787110 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    17 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |    92 node`ssleay_rand_add+0xcb
    131072 |@@@@@@@@@               |   401 node`ssl3_accept+0x31
    262144 |@@@@@                   |   219 node`ssl3_read_bytes+0x17a
    524288 |@@                      |    90 node`ssl3_read_internal+0xc1
   1048576 |@                       |    61 
   2097152 |@                       |    66 
   4194304 |@                       |    45 
   8388608 |                        |    17 
  16777216 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7315   104564 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |   816 node`def_get_class+0x4f
     65536 |@@@@@@@@                |  2735 node`int_new_ex_data+0x1d
    131072 |@@@@@@@@@@@             |  3448 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |   276 node`ssl3_output_cert_chain+0xcd
    524288 |                        |    22 
   1048576 |                        |    12 
   2097152 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1204   536834 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    17 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   108 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@              |   525 node`ssl3_accept+0x31
    262144 |@@@@@                   |   278 node`ssl3_read_bytes+0x17a
    524288 |@@                      |   104 node`ssl3_read_internal+0xc1
   1048576 |@                       |    54 
   2097152 |@                       |    74 
   4194304 |                        |    33 
   8388608 |                        |    11 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1655   162850 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   181 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |   584 node`def_get_class+0x4f
    131072 |@@@@@@@@                |   607 node`int_free_ex_data+0x1d
    262144 |@@                      |   166 node`BIO_free+0x76
    524288 |                        |    67 node`ssl_free_wbio_buffer+0x2d
   1048576 |                        |    36 
   2097152 |                        |    14 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1858   136133 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   231 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |   590 node`def_get_class+0x4f
    131072 |@@@@@@@@@@              |   819 node`int_free_ex_data+0x1d
    262144 |@@                      |   159 node`SSL_free+0x65
    524288 |                        |    32 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
   1048576 |                        |    17 
   2097152 |                        |     9 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1480   122592 0x102008990                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@                     |   191 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |   545 node`def_get_class+0x4f
    131072 |@@@@@@@@@               |   600 node`int_free_ex_data+0x1d
    262144 |@                       |    96 node`SSL_SESSION_free+0x54
    524288 |                        |    34 node`SSL_free+0xfe
   1048576 |                        |    11 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   72   518371 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     3 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |     8 node`ssleay_rand_add+0xcb
    131072 |@@@@@@@@@               |    28 node`bnrand+0xbc
    262144 |@@@@@                   |    16 node`bn_rand_range+0x13c
    524288 |@@                      |     7 node`BN_BLINDING_create_param+0xc2
   1048576 |@                       |     4 
   2097152 |                        |     2 
   4194304 |@                       |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   67   484183 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     2 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |     8 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@@@            |    35 node`bnrand+0xbc
    262144 |@@@@                    |    12 node`bn_rand_range+0x13c
    524288 |@                       |     4 node`BN_BLINDING_create_param+0xc2
   1048576 |                        |     1 
   2097152 |                        |     2 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   48   596650 0x102009098                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     2 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@                   |    10 node`X509_STORE_get_by_subject+0x3d
    131072 |@@@@@                   |    11 node`X509_STORE_CTX_get1_issuer+0x48
    262144 |@@@@@@                  |    13 node`X509_verify_cert+0x2a9
    524288 |@@@                     |     6 node`ssl3_output_cert_chain+0x103
   1048576 |                        |     1 
   2097152 |                        |     1 
   4194304 |@@                      |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   76   330266 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     2 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |    12 node`ssleay_rand_bytes+0x40a
    131072 |@@@@@@@@@@@             |    37 node`bnrand+0xe0
    262144 |@@@@@                   |    18 node`bn_rand_range+0x13c
    524288 |                        |     2 node`BN_BLINDING_create_param+0xc2
   1048576 |                        |     1 
   2097152 |                        |     2 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   44   469178 0x102009610                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     65536 |@                       |     3 node`uv_rwlock_wrlock+0x9
    131072 |@@@@@@@@@@@@            |    22 node`ssleay_rand_bytes+0x7a
    262144 |@@@@@@                  |    11 node`bnrand+0xe0
    524288 |                        |     0 node`bn_rand_range+0x13c
   1048576 |@@                      |     4 node`BN_BLINDING_create_param+0xc2
   2097152 |@                       |     3 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   262144 0x102008f08                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
    262144 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_rwlock_wrlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x79
                                            node`RSA_eay_mod_exp+0x157
                                            node`RSA_eay_private_decrypt+0x22e
                                            node`ssl3_get_client_key_exchange+0x159
```

Without patches:
```
Time taken for tests:   110.771 seconds

Mutex block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
42420    95289 0x1030007d8                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |  3149 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |  1917 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |  9602 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              | 19179 node`CRYPTO_add_lock+0x64
    131072 |@@@                     |  6643 node`EVP_PKEY_free+0x31
    262144 |                        |  1033 
    524288 |                        |   420 
   1048576 |                        |   219 
   2097152 |                        |   166 
   4194304 |                        |    73 
   8388608 |                        |    18 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
37297    94203 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   205 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |  2384 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                | 13169 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@               | 14560 node`EVP_PKEY_CTX_dup+0xb4
    131072 |@@@                     |  5247 node`EVP_MD_CTX_copy_ex+0x13c
    262144 |                        |   808 
    524288 |                        |   409 
   1048576 |                        |   290 
   2097152 |                        |   161 
   4194304 |                        |    49 
   8388608 |                        |    15 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
48075    70257 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |  6076 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@                  | 12143 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   | 11977 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@                  | 12219 node`EVP_PKEY_CTX_dup+0xb4
    131072 |@@                      |  4056 node`EVP_MD_CTX_copy_ex+0x13c
    262144 |                        |   716 
    524288 |                        |   378 
   1048576 |                        |   247 
   2097152 |                        |   192 
   4194304 |                        |    59 
   8388608 |                        |    11 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
47534    66230 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |  4982 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 | 14366 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  | 12447 node`CRYPTO_add_lock+0x64
     65536 |@@@@@                   | 10744 node`EVP_PKEY_free+0x31
    131072 |@                       |  3642 node`EVP_PKEY_CTX_free+0x32
    262144 |                        |   561 
    524288 |                        |   324 
   1048576 |                        |   239 
   2097152 |                        |   153 
   4194304 |                        |    58 
   8388608 |                        |    18 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
35318    88196 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   167 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |  2576 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               | 14042 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@                | 12586 node`EVP_PKEY_free+0x31
    131072 |@@@                     |  4519 node`EVP_PKEY_CTX_free+0x32
    262144 |                        |   667 
    524288 |                        |   340 
   1048576 |                        |   224 
   2097152 |                        |   131 
   4194304 |                        |    53 
   8388608 |                        |    13 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
28771    99396 0x1030007d8                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |  2022 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |  1256 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |  6173 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              | 13069 node`CRYPTO_add_lock+0x64
    131072 |@@@                     |  4791 node`EVP_PKEY_CTX_dup+0xb4
    262144 |                        |   819 
    524288 |                        |   281 
   1048576 |                        |   166 
   2097152 |                        |   134 
   4194304 |                        |    48 
   8388608 |                        |    10 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
10030   174382 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   554 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |  2023 node`uv_rwlock_wrlock+0x9
     32768 |@@@                     |  1539 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@@                 |  3106 node`int_ctx_new+0x14f
    131072 |@@@                     |  1589 node`do_sigver_init+0x41
    262144 |@                       |   479 
    524288 |                        |   277 
   1048576 |                        |   209 
   2097152 |                        |   172 
   4194304 |                        |    71 
   8388608 |                        |    10 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
21149    71425 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   886 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |  2410 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  4559 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  9995 node`int_new_ex_data+0x1d
    131072 |@@@                     |  2871 node`BIO_set+0x91
    262144 |                        |   258 
    524288 |                        |    77 
   1048576 |                        |    53 
   2097152 |                        |    31 
   4194304 |                        |     5 
   8388608 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
15021    93310 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    42 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   379 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |  1562 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@            |  7588 node`BIO_set+0x91
    131072 |@@@@@@@@                |  5111 node`BIO_new+0x5f
    262144 |                        |   234 
    524288 |                        |    54 
   1048576 |                        |    27 
   2097152 |                        |    20 
   4194304 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
12471   105333 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   446 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |  1272 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  2429 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  5730 node`int_free_ex_data+0x1d
    131072 |@@@                     |  1973 node`BIO_free+0x69
    262144 |                        |   277 
    524288 |                        |   141 
   1048576 |                        |   107 
   2097152 |                        |    65 
   4194304 |                        |    21 
   8388608 |                        |     9 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9091   136118 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    36 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   478 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |  2446 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@               |  3737 node`int_ctx_new+0x14f
    131072 |@@@@                    |  1619 node`do_sigver_init+0x41
    262144 |                        |   348 
    524288 |                        |   178 
   1048576 |                        |   120 
   2097152 |                        |    98 
   4194304 |                        |    20 
   8388608 |                        |    11 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
16238    71307 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   281 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |  1174 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  4133 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  7795 node`int_new_ex_data+0x4d
    131072 |@@@                     |  2625 node`BIO_set+0x91
    262144 |                        |   137 
    524288 |                        |    52 
   1048576 |                        |    23 
   2097152 |                        |    12 
   4194304 |                        |     4 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9437   106543 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |  1132 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |  2016 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  1965 node`int_thread_get+0x26
     65536 |@@@@@@@                 |  2820 node`int_thread_get_item+0x1f
    131072 |@@                      |   937 node`ERR_get_state+0x47
    262144 |                        |   253 
    524288 |                        |   121 
   1048576 |                        |    88 
   2097152 |                        |    60 
   4194304 |                        |    34 
   8388608 |                        |    10 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 9644    93169 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   548 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |  2978 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |  2587 node`CRYPTO_add_lock+0x64
     65536 |@@@@@                   |  2236 node`EVP_PKEY_free+0x31
    131072 |@@                      |   826 node`tls1_change_cipher_state+0x48a
    262144 |                        |   161 
    524288 |                        |   106 
   1048576 |                        |    91 
   2097152 |                        |    89 
   4194304 |                        |    18 
   8388608 |                        |     2 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
15327    53331 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |  3560 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   673 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |  4119 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@                |  5590 node`def_get_class+0x4f
    131072 |@                       |  1221 node`int_new_ex_data+0x1d
    262144 |                        |    90 
    524288 |                        |    38 
   1048576 |                        |    15 
   2097152 |                        |    17 
   4194304 |                        |     3 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
10577    74123 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    53 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   665 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |  3226 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@             |  5251 node`int_new_ex_data+0x1d
    131072 |@@                      |  1137 node`BIO_set+0x91
    262144 |                        |   123 
    524288 |                        |    64 
   1048576 |                        |    37 
   2097152 |                        |    15 
   4194304 |                        |     3 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6436   115954 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    53 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   415 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |  1884 node`int_thread_get+0xa0
     65536 |@@@@@@@@@               |  2533 node`int_thread_get_item+0x1f
    131072 |@@@@                    |  1119 node`ERR_get_state+0x47
    262144 |                        |   205 
    524288 |                        |   103 
   1048576 |                        |    67 
   2097152 |                        |    35 
   4194304 |                        |    17 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6852    95684 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   281 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |   558 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  1167 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  3404 node`int_new_ex_data+0x1d
    131072 |@@@@                    |  1179 node`SSL_new+0x31f
    262144 |                        |   145 
    524288 |                        |    51 
   1048576 |                        |    32 
   2097152 |                        |    18 
   4194304 |                        |    12 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8111    78996 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   195 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   638 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  2118 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  3844 node`int_free_ex_data+0x44
    131072 |@@@                     |  1127 node`BIO_free+0x69
    262144 |                        |   109 
    524288 |                        |    34 
   1048576 |                        |    24 
   2097152 |                        |    14 
   4194304 |                        |     4 
   8388608 |                        |     3 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6715    93039 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    21 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   302 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |  1696 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@@            |  3435 node`int_free_ex_data+0x1d
    131072 |@@@                     |   982 node`BIO_free+0x69
    262144 |                        |   130 
    524288 |                        |    68 
   1048576 |                        |    50 
   2097152 |                        |    22 
   4194304 |                        |     8 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6583    94827 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    24 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   409 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |  2596 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@                |  2314 node`EVP_PKEY_free+0x31
    131072 |@@@                     |   908 node`tls1_change_cipher_state+0x48a
    262144 |                        |   144 
    524288 |                        |    89 
   1048576 |                        |    55 
   2097152 |                        |    35 
   4194304 |                        |     7 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4086   145124 0x1030007d8                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   205 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   180 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |   711 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |  1840 node`CRYPTO_add_lock+0x64
    131072 |@@@@                    |   763 node`int_ctx_new+0x14f
    262144 |@                       |   198 
    524288 |                        |    76 
   1048576 |                        |    47 
   2097152 |                        |    45 
   4194304 |                        |    16 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5193   104266 0x1030000d0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   232 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   340 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@                   |  1130 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2407 node`int_thread_get_item+0x46
    131072 |@@@                     |   808 node`ERR_get_state+0x47
    262144 |                        |   136 
    524288 |                        |    61 
   1048576 |                        |    46 
   2097152 |                        |    20 
   4194304 |                        |    10 
   8388608 |                        |     2 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8670    58548 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |  1877 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |   350 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |  2229 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@               |  3395 node`def_get_class+0x4f
    131072 |@                       |   669 node`int_free_ex_data+0x1d
    262144 |                        |    82 
    524288 |                        |    32 
   1048576 |                        |    22 
   2097152 |                        |    10 
   4194304 |                        |     3 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4173   114974 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   332 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |   742 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |   714 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@@@                |  1435 node`X509_PUBKEY_get+0x45
    131072 |@@@                     |   671 node`X509_get_pubkey_parameters+0x44
    262144 |                        |   132 
    524288 |                        |    67 
   1048576 |                        |    39 
   2097152 |                        |    21 
   4194304 |                        |    15 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5305    88047 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    58 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |   266 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |  1149 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@@@@@@@@           |  3049 node`int_thread_release+0x3a
    131072 |@@                      |   615 node`int_thread_get_item+0x7e
    262144 |                        |    86 
    524288 |                        |    32 
   1048576 |                        |    24 
   2097152 |                        |    16 
   4194304 |                        |     9 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4633    99011 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    18 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   121 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   436 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@            |  2353 node`SSL_new+0x31f
    131072 |@@@@@@@                 |  1538 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    262144 |                        |   102 
    524288 |                        |    36 
   1048576 |                        |    21 
   2097152 |                        |     7 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6163    70410 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   421 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |   483 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  1252 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@@            |  3116 node`int_free_ex_data+0x1d
    131072 |@@@                     |   771 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    71 
    524288 |                        |    26 
   1048576 |                        |    12 
   2097152 |                        |     9 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6179    69126 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   582 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   541 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  1237 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  2989 node`int_new_ex_data+0x1d
    131072 |@@                      |   709 node`SSL_SESSION_new+0xf7
    262144 |                        |    73 
    524288 |                        |    22 
   1048576 |                        |    11 
   2097152 |                        |    12 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3996   105866 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |   601 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   492 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |   866 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@@                 |  1308 node`ssl_cert_dup+0x1fa
    131072 |@@@                     |   510 node`SSL_new+0xc6
    262144 |                        |    94 
    524288 |                        |    52 
   1048576 |                        |    31 
   2097152 |                        |    21 
   4194304 |                        |    18 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4293    94888 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    10 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   110 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   386 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@@            |  2238 node`BIO_free+0x69
    131072 |@@@@@@@                 |  1428 node`ssl3_digest_cached_records+0x186
    262144 |                        |    77 
    524288 |                        |    28 
   1048576 |                        |     9 
   2097152 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5994    65620 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   550 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   584 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |  1128 node`def_get_class+0x4f
     65536 |@@@@@@@@@@@             |  2949 node`int_new_ex_data+0x1d
    131072 |@@                      |   683 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    63 
    524288 |                        |    20 
   1048576 |                        |     7 
   2097152 |                        |     8 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3982    97962 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    92 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   365 node`int_new_ex_data+0x142
     65536 |@@@@@@@@@@@@            |  2114 node`SSL_SESSION_new+0xf7
    131072 |@@@@@@@                 |  1286 node`ssl_get_new_session+0x33
    262144 |                        |    77 
    524288 |                        |    22 
   1048576 |                        |    10 
   2097152 |                        |     7 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4151    93788 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    24 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   152 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   491 node`int_free_ex_data+0xb9
     65536 |@@@@@@@@@@@@            |  2076 node`X509_STORE_CTX_cleanup+0x96
    131072 |@@@@@@@                 |  1287 node`ssl3_output_cert_chain+0x15f
    262144 |                        |    85 
    524288 |                        |    19 
   1048576 |                        |    10 
   2097152 |                        |     5 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3551   107289 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    15 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   168 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |   911 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@@@             |  1628 node`X509_PUBKEY_get+0x45
    131072 |@@@@                    |   645 node`X509_get_pubkey_parameters+0x44
    262144 |                        |    87 
    524288 |                        |    44 
   1048576 |                        |    26 
   2097152 |                        |    18 
   4194304 |                        |     7 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4739    80161 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    73 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   348 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  1255 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  2229 node`int_new_ex_data+0x4d
    131072 |@@@                     |   712 node`SSL_new+0x31f
    262144 |                        |    65 
    524288 |                        |    27 
   1048576 |                        |    17 
   2097152 |                        |     9 
   4194304 |                        |     2 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3950    94701 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    39 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   146 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   465 node`int_new_ex_data+0xc2
     65536 |@@@@@@@@@@@@            |  1980 node`X509_STORE_CTX_init+0x2ca
    131072 |@@@@@@@                 |  1185 node`ssl3_output_cert_chain+0xcd
    262144 |                        |    93 
    524288 |                        |    25 
   1048576 |                        |    12 
   2097152 |                        |     2 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5103    68077 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   239 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   650 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@@             |  2371 node`int_new_ex_data+0x4d
     65536 |@@@@@@                  |  1351 node`BIO_set+0x91
    131072 |@                       |   360 node`BIO_new+0x5f
    262144 |                        |    61 
    524288 |                        |    29 
   1048576 |                        |    20 
   2097152 |                        |    17 
   4194304 |                        |     2 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3344   103686 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    41 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   240 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@                   |   703 node`int_thread_get_item+0x70
     65536 |@@@@@@@@@@              |  1506 node`ERR_get_state+0x47
    131072 |@@@@                    |   612 node`get_error_values+0x33
    262144 |                        |   138 
    524288 |                        |    53 
   1048576 |                        |    37 
   2097152 |                        |    10 
   4194304 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3187   105799 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    12 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |   124 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |   883 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@@@             |  1467 node`ssl_cert_dup+0x1fa
    131072 |@@@@                    |   552 node`SSL_new+0xc6
    262144 |                        |    63 
    524288 |                        |    43 
   1048576 |                        |    22 
   2097152 |                        |    12 
   4194304 |                        |     6 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3489    94453 0x1030000d0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   320 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   202 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@                     |   558 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@@            |  1797 node`int_thread_get+0x26
    131072 |@@@                     |   457 node`int_thread_get_item+0x1f
    262144 |                        |    83 
    524288 |                        |    30 
   1048576 |                        |    18 
   2097152 |                        |    16 
   4194304 |                        |     7 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3431    94178 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    16 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   160 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@                    |   711 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@@            |  1845 node`int_new_ex_data+0x1d
    131072 |@@@@                    |   582 node`SSL_new+0x31f
    262144 |                        |    61 
    524288 |                        |    22 
   1048576 |                        |    17 
   2097152 |                        |    14 
   4194304 |                        |     2 
   8388608 |                        |     0 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2851   113147 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    36 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   165 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@                    |   555 node`int_thread_get_item+0x70
     65536 |@@@@@@@@@@@             |  1381 node`ERR_get_state+0x47
    131072 |@@@@                    |   547 node`ERR_clear_error+0xc
    262144 |                        |    87 
    524288 |                        |    32 
   1048576 |                        |    25 
   2097152 |                        |    15 
   4194304 |                        |     6 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2657   107935 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   164 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |   234 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |   530 node`def_get_class+0x4f
     65536 |@@@@@@@@@               |  1100 node`int_free_ex_data+0x1d
    131072 |@@@@                    |   454 node`SSL_free+0x65
    262144 |                        |    90 
    524288 |                        |    42 
   1048576 |                        |    19 
   2097152 |                        |    16 
   4194304 |                        |     8 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3912    68876 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    67 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   336 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  1118 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  1850 node`int_new_ex_data+0x4d
    131072 |@@@                     |   491 node`SSL_SESSION_new+0xf7
    262144 |                        |    27 
    524288 |                        |     5 
   1048576 |                        |    10 
   2097152 |                        |     6 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3830    69396 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    67 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   333 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |  1074 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  1773 node`int_free_ex_data+0x44
    131072 |@@@                     |   533 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    33 
    524288 |                        |     3 
   1048576 |                        |     7 
   2097152 |                        |     6 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2553    98794 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    11 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    65 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |   332 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@             |  1191 node`BIO_free+0x69
    131072 |@@@@@@@                 |   843 node`BIO_free_all+0x15
    262144 |                        |    69 
    524288 |                        |    24 
   1048576 |                        |    16 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1578   158305 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   142 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@                       |    98 node`uv_rwlock_wrlock+0x9
     32768 |@@@                     |   257 node`ssleay_rand_add+0xcb
     65536 |@@@@@@@@@               |   649 node`ssl23_accept+0x2f
    131072 |@@@@                    |   294 node`ssl23_read+0x4e
    262144 |                        |    61 
    524288 |                        |    30 
   1048576 |                        |    22 
   2097152 |                        |     9 
   4194304 |                        |    12 
   8388608 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  439   546774 0x103000710                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     3 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@                       |    21 node`uv_rwlock_rdlock+0x9
     32768 |@@                      |    48 node`rsa_get_blinding+0x41
     65536 |@@@@@                   |   107 node`RSA_eay_private_decrypt+0x179
    131072 |@@@                     |    67 node`ssl3_get_client_key_exchange+0x159
    262144 |@@@                     |    62 
    524288 |@@                      |    43 
   1048576 |@@                      |    41 
   2097152 |@                       |    35 
   4194304 |                        |     8 
   8388608 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2233   107123 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    92 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   266 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@                |   750 node`int_thread_get_item+0x46
     65536 |@@@@@@@@                |   771 node`ERR_get_state+0x47
    131072 |@@                      |   223 node`get_error_values+0x33
    262144 |                        |    65 
    524288 |                        |    21 
   1048576 |                        |    17 
   2097152 |                        |    22 
   4194304 |                        |     3 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3578    66525 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |   100 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   348 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |   993 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |  1642 node`int_new_ex_data+0x4d
    131072 |@@@                     |   451 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    23 
    524288 |                        |    12 
   1048576 |                        |     5 
   2097152 |                        |     3 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1671   139175 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     3 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    59 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   197 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@              |   705 node`BIO_free+0x69
    131072 |@@@@@@@@                |   575 node`ssl_free_wbio_buffer+0x2d
    262144 |@                       |    75 
    524288 |                        |    26 
   1048576 |                        |    13 
   2097152 |                        |    13 
   4194304 |                        |     3 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2525    84580 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |   162 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |   514 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |   800 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@                  |   726 node`EVP_PKEY_free+0x31
    131072 |@                       |   204 node`X509_get_pubkey_parameters+0xd6
    262144 |                        |    46 
    524288 |                        |    36 
   1048576 |                        |    19 
   2097152 |                        |    15 
   4194304 |                        |     1 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2665    78102 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    16 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   124 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |   844 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@@@             |  1319 node`int_thread_release+0x3a
    131072 |@@                      |   273 node`int_thread_get_item+0x7e
    262144 |                        |    62 
    524288 |                        |     8 
   1048576 |                        |    10 
   2097152 |                        |     6 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1552   130406 0x1030007d8                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    80 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |    63 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |   289 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |   682 node`CRYPTO_add_lock+0x64
    131072 |@@@@                    |   302 node`X509_PUBKEY_get+0x45
    262144 |@                       |    68 
    524288 |                        |    32 
   1048576 |                        |    19 
   2097152 |                        |    11 
   4194304 |                        |     5 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  588   339995 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@                   |   126 node`uv_rwlock_rdunlock+0x9
     65536 |@@@@@@@                 |   186 node`BN_MONT_CTX_set_locked+0xe2
    131072 |@@@@                    |   100 node`RSA_eay_mod_exp+0x17c
    262144 |@                       |    38 node`RSA_eay_private_decrypt+0x22e
    524288 |@@                      |    50 
   1048576 |@                       |    42 
   2097152 |@                       |    37 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  694   285787 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    41 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |    79 node`uv_rwlock_wrlock+0x9
     32768 |@@@                     |    87 node`ssleay_rand_add+0xcb
     65536 |@@@@@@@                 |   224 node`ssl3_accept+0x31
    131072 |@@@@                    |   123 node`ssl3_read_bytes+0x17a
    262144 |@                       |    56 
    524288 |                        |    25 
   1048576 |@                       |    29 
   2097152 |                        |    20 
   4194304 |                        |     5 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1822   108123 0x1030007d8                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    80 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |    74 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@                     |   301 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@             |   889 node`CRYPTO_add_lock+0x64
    131072 |@@@@                    |   373 node`ssl_cert_dup+0x1fa
    262144 |                        |    52 
    524288 |                        |    25 
   1048576 |                        |    17 
   2097152 |                        |     8 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2817    69409 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    18 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   167 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |  1005 node`def_get_class+0xd5
     65536 |@@@@@@@@@@              |  1249 node`int_new_ex_data+0x1d
    131072 |@@                      |   316 node`SSL_SESSION_new+0xf7
    262144 |                        |    39 
    524288 |                        |    12 
   1048576 |                        |     7 
   2097152 |                        |     2 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2626    73871 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    12 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   170 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |   782 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@             |  1261 node`int_free_ex_data+0x1d
    131072 |@@@                     |   334 node`X509_STORE_CTX_cleanup+0x96
    262144 |                        |    39 
    524288 |                        |    15 
   1048576 |                        |     6 
   2097152 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2869    65872 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   280 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   851 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   830 node`CRYPTO_add_lock+0x64
     65536 |@@@@@                   |   631 node`EVP_PKEY_free+0x31
    131072 |@                       |   193 node`ssl_cert_free+0x87
    262144 |                        |    33 
    524288 |                        |    24 
   1048576 |                        |    15 
   2097152 |                        |     6 
   4194304 |                        |     5 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2638    70563 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    21 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   155 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   956 node`def_get_class+0xd5
     65536 |@@@@@@@@@@              |  1183 node`int_new_ex_data+0x1d
    131072 |@@                      |   275 node`X509_STORE_CTX_init+0x2ca
    262144 |                        |    25 
    524288 |                        |     7 
   1048576 |                        |     9 
   2097152 |                        |     5 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  595   311447 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     5 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    24 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@                   |   144 node`BN_MONT_CTX_set_locked+0xe2
     65536 |@@@@@@@                 |   189 node`RSA_eay_mod_exp+0x137
    131072 |@@@                     |    82 node`RSA_eay_private_decrypt+0x22e
    262144 |@@                      |    53 
    524288 |@                       |    31 
   1048576 |@                       |    25 
   2097152 |@                       |    36 
   4194304 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  498   358325 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     3 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    16 node`uv_rwlock_rdunlock+0x9
     32768 |@@@                     |    73 node`rsa_get_blinding+0x18f
     65536 |@@@@@@@@                |   174 node`RSA_eay_private_decrypt+0x179
    131072 |@@@@                    |    84 node`ssl3_get_client_key_exchange+0x159
    262144 |@@                      |    53 
    524288 |@                       |    30 
   1048576 |@                       |    30 
   2097152 |@                       |    30 
   4194304 |                        |     3 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2057    84851 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    10 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   150 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |   803 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@                |   735 node`EVP_PKEY_free+0x31
    131072 |@@@                     |   278 node`ssl_cert_free+0x87
    262144 |                        |    43 
    524288 |                        |    15 
   1048576 |                        |    12 
   2097152 |                        |     8 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  605   287112 0x103000710                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |                        |    13 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@                  |   162 node`BN_MONT_CTX_set_locked+0x3e
     65536 |@@@@@@@@                |   212 node`RSA_eay_mod_exp+0x157
    131072 |@@@                     |    95 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    41 
    524288 |@                       |    26 
   1048576 |                        |    20 
   2097152 |@                       |    26 
   4194304 |                        |     6 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1639   104541 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    50 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   203 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@              |   734 node`SSL_free+0x65
    131072 |@@@@@@@@                |   569 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    262144 |                        |    55 
    524288 |                        |    11 
   1048576 |                        |     8 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  597   283522 0x103000710                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     9 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     32768 |@@@@@@                  |   159 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@                |   207 node`BN_MONT_CTX_set_locked+0x3e
    131072 |@@@                     |    89 node`RSA_eay_mod_exp+0x17c
    262144 |@                       |    43 node`RSA_eay_private_decrypt+0x22e
    524288 |@                       |    31 
   1048576 |                        |    24 
   2097152 |@                       |    31 
   4194304 |                        |     3 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  606   265726 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    10 node`uv_rwlock_rdunlock+0x9
     32768 |@@@@@@                  |   171 node`BN_MONT_CTX_set_locked+0xe2
     65536 |@@@@@@@@                |   205 node`RSA_eay_mod_exp+0x157
    131072 |@@@                     |    96 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    35 
    524288 |@                       |    33 
   1048576 |@                       |    26 
   2097152 |                        |    22 
   4194304 |                        |     7 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  528   303243 0x103000710                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     9 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |    46 node`uv_rwlock_rdlock+0x9
     32768 |@@@@                    |    93 node`BN_MONT_CTX_set_locked+0x3e
     65536 |@@@@@@@                 |   158 node`RSA_eay_mod_exp+0x137
    131072 |@@@@                    |   101 node`RSA_eay_private_decrypt+0x22e
    262144 |@                       |    34 
    524288 |@                       |    32 
   1048576 |@                       |    24 
   2097152 |@                       |    25 
   4194304 |                        |     5 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1439   100541 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     9 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    60 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |   383 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@@@              |   658 node`ssl23_accept+0x2f
    131072 |@@@@                    |   247 node`ssl23_read+0x4e
    262144 |                        |    50 
    524288 |                        |    15 
   1048576 |                        |     9 
   2097152 |                        |     6 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1654    87387 0x1030007d8                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     8 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |   108 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |   655 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@                |   588 node`EVP_PKEY_free+0x31
    131072 |@@@                     |   231 node`X509_get_pubkey_parameters+0xd6
    262144 |                        |    32 
    524288 |                        |    12 
   1048576 |                        |    14 
   2097152 |                        |     3 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1454    97171 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     7 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    68 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |   386 node`def_get_class+0xd5
     65536 |@@@@@@@@@@@             |   679 node`int_free_ex_data+0x1d
    131072 |@@@@                    |   247 node`SSL_free+0x65
    262144 |                        |    27 
    524288 |                        |    19 
   1048576 |                        |    12 
   2097152 |                        |     8 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1614    85381 0x1030000d0                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    84 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   211 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@                |   571 node`int_thread_get_item+0x46
     65536 |@@@@@@@                 |   530 node`ERR_get_state+0x47
    131072 |@@                      |   144 node`ERR_clear_error+0xc
    262144 |                        |    34 
    524288 |                        |    12 
   1048576 |                        |    18 
   2097152 |                        |     7 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1261    99928 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    39 node`uv_rwlock_rdunlock+0x9
     32768 |@@                      |   143 node`int_free_ex_data+0x147
     65536 |@@@@@@@@@@@             |   605 node`SSL_SESSION_free+0x54
    131072 |@@@@@@@                 |   412 node`SSL_free+0xfe
    262144 |                        |    35 
    524288 |                        |    14 
   1048576 |                        |     8 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1666    74632 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    46 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |   118 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |   418 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@@             |   773 node`int_free_ex_data+0x44
    131072 |@@@                     |   262 node`SSL_free+0x65
    262144 |                        |    31 
    524288 |                        |    13 
   1048576 |                        |     2 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1296    92463 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   128 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |    62 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |   350 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |   562 node`ssleay_rand_bytes+0x7a
    131072 |@@                      |   138 node`ssleay_rand_pseudo_bytes+0xe
    262144 |                        |    36 
    524288 |                        |     4 
   1048576 |                        |     4 
   2097152 |                        |     9 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1675    69477 0x103000198                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    88 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@                     |   213 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |   391 node`def_get_class+0x4f
     65536 |@@@@@@@@@               |   688 node`int_free_ex_data+0x1d
    131072 |@@@                     |   256 node`SSL_SESSION_free+0x54
    262144 |                        |    27 
    524288 |                        |     6 
   1048576 |                        |     2 
   2097152 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1162    97662 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   109 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |    44 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@@                  |   316 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@               |   481 node`ssleay_rand_bytes+0x40a
    131072 |@@@                     |   162 node`ssleay_rand_pseudo_bytes+0xe
    262144 |                        |    30 
    524288 |                        |     8 
   1048576 |                        |     7 
   2097152 |                        |     0 
   4194304 |                        |     3 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1264    88018 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    91 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@                   |   309 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@                 |   418 node`ssleay_rand_bytes+0x452
     65536 |@@@@@                   |   276 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@@                      |   110 node`ssl3_get_client_hello+0x56d
    262144 |                        |    26 
    524288 |                        |    18 
   1048576 |                        |    11 
   2097152 |                        |     1 
   4194304 |                        |     1 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  643   158336 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |                        |    19 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@                   |   145 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@@@              |   278 node`ssl3_accept+0x31
    131072 |@@@@                    |   125 node`ssl3_read_bytes+0x17a
    262144 |@                       |    29 
    524288 |                        |    20 
   1048576 |                        |    18 
   2097152 |                        |     2 
   4194304 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1450    69931 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    80 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   149 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@               |   574 node`int_new_ex_data+0x4d
     65536 |@@@@@@@                 |   477 node`SSL_new+0x31f
    131072 |@@                      |   126 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    262144 |                        |    21 
    524288 |                        |    10 
   1048576 |                        |     8 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  929   100393 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    33 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   126 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@                |   321 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   291 node`BIO_free+0x69
    131072 |@@                      |    96 node`ssl_free_wbio_buffer+0x2d
    262144 |                        |    24 
    524288 |                        |    13 
   1048576 |                        |    16 
   2097152 |                        |     9 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1201    76319 0x1030000d0                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |   173 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |   116 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |   240 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |   510 node`CRYPTO_add_lock+0x64
    131072 |@@                      |   119 node`int_thread_release+0x3a
    262144 |                        |    22 
    524288 |                        |     9 
   1048576 |                        |     6 
   2097152 |                        |     5 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1024    88480 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    46 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |   165 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   347 node`ssleay_rand_bytes+0x235
     65536 |@@@@@@@                 |   312 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@@                      |   101 node`def_generate_session_id+0x28
    262144 |                        |    32 
    524288 |                        |    11 
   1048576 |                        |     7 
   2097152 |                        |     2 
   4194304 |                        |     0 
   8388608 |                        |     0 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1320    67255 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    81 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   164 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   561 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   385 node`X509_STORE_CTX_cleanup+0x96
    131072 |@                       |    99 node`ssl3_output_cert_chain+0x15f
    262144 |                        |    14 
    524288 |                        |     8 
   1048576 |                        |     4 
   2097152 |                        |     2 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1144    75718 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    54 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |   210 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   425 node`ssleay_rand_bytes+0x235
     65536 |@@@@@@                  |   318 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |    90 node`ssl3_get_client_hello+0x56d
    262144 |                        |    24 
    524288 |                        |    13 
   1048576 |                        |     4 
   2097152 |                        |     3 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  812   106112 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    70 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |    34 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |   191 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |   362 node`ssleay_rand_add+0x367
    131072 |@@@                     |   106 node`ssl3_accept+0x31
    262144 |                        |    23 
    524288 |                        |    11 
   1048576 |                        |     8 
   2097152 |                        |     4 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1297    64557 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    77 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   140 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   558 node`int_new_ex_data+0x4d
     65536 |@@@@@@                  |   376 node`SSL_SESSION_new+0xf7
    131072 |@@                      |   111 node`ssl_get_new_session+0x33
    262144 |                        |    17 
    524288 |                        |     8 
   1048576 |                        |     8 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  789   105738 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    52 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |    30 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |   150 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@@            |   400 node`ssleay_rand_add+0xcb
    131072 |@@@                     |   112 node`ssl3_accept+0x31
    262144 |                        |    24 
    524288 |                        |    10 
   1048576 |                        |     4 
   2097152 |                        |     4 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1126    70359 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    63 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   156 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   504 node`int_free_ex_data+0x44
     65536 |@@@@@@                  |   284 node`BIO_free+0x69
    131072 |@                       |    81 node`BIO_free_all+0x15
    262144 |                        |    16 
    524288 |                        |     8 
   1048576 |                        |     9 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  916    85479 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     6 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |    80 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   336 node`ssleay_rand_add+0x1cf
     65536 |@@@@@@@@@               |   352 node`ssl3_accept+0x31
    131072 |@@                      |   101 node`ssl23_get_client_hello+0x660
    262144 |                        |    27 
    524288 |                        |     7 
   1048576 |                        |     4 
   2097152 |                        |     1 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1107    70368 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    57 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@                   |   258 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   398 node`ssleay_rand_bytes+0x452
     65536 |@@@@@                   |   246 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@@                      |    96 node`def_generate_session_id+0x28
    262144 |                        |    30 
    524288 |                        |    11 
   1048576 |                        |     7 
   2097152 |                        |     3 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1312    58942 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    76 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@@                     |   180 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   559 node`int_free_ex_data+0x44
     65536 |@@@@@@                  |   380 node`BIO_free+0x69
    131072 |@                       |    93 node`ssl3_digest_cached_records+0x186
    262144 |                        |    10 
    524288 |                        |     6 
   1048576 |                        |     6 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1253    59037 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    80 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |   139 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@@              |   540 node`int_new_ex_data+0x4d
     65536 |@@@@@@@                 |   370 node`X509_STORE_CTX_init+0x2ca
    131072 |@                       |    92 node`ssl3_output_cert_chain+0xcd
    262144 |                        |    17 
    524288 |                        |    10 
   1048576 |                        |     3 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  906    78348 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    13 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |   126 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |   342 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@@                 |   285 node`ssl23_accept+0x2f
    131072 |@@                      |    99 node`ssl23_read+0x4e
    262144 |                        |    25 
    524288 |                        |     9 
   1048576 |                        |     6 
   2097152 |                        |     0 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1217    58192 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |   287 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |   255 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   320 node`ssleay_rand_bytes+0x7a
     65536 |@@@@                    |   237 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |    86 node`ssl3_get_client_hello+0x56d
    262144 |                        |    17 
    524288 |                        |     7 
   1048576 |                        |     4 
   2097152 |                        |     1 
   4194304 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  868    80306 0x103000198                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     7 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |    77 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   325 node`def_get_class+0xd5
     65536 |@@@@@@@@@               |   333 node`int_free_ex_data+0x1d
    131072 |@@                      |    94 node`SSL_SESSION_free+0x54
    262144 |                        |    18 
    524288 |                        |     8 
   1048576 |                        |     4 
   2097152 |                        |     1 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1027    65129 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |   243 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@                     |   149 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |   214 node`ssleay_rand_add+0xcb
     65536 |@@@@@@                  |   292 node`ssl3_accept+0x31
    131072 |@@                      |    93 node`ssl23_get_client_hello+0x660
    262144 |                        |    22 
    524288 |                        |     7 
   1048576 |                        |     4 
   2097152 |                        |     1 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1072    61646 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |   107 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   328 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   274 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |   264 node`ssl23_accept+0x2f
    131072 |@                       |    68 node`ssl23_read+0x4e
    262144 |                        |    16 
    524288 |                        |     5 
   1048576 |                        |     5 
   2097152 |                        |     4 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1018    64449 0x103000198                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    29 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@@                      |    94 libSystem.B.dylib`pthread_rwlock_rdlock+0x103
     32768 |@@@@@@                  |   284 node`uv_rwlock_rdlock+0x9
     65536 |@@@@@@@@@@              |   446 node`int_free_ex_data+0x44
    131072 |@@@                     |   153 node`SSL_SESSION_free+0x54
    262144 |                        |     6 
    524288 |                        |     5 
   1048576 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  726    89040 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    57 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |    27 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@@                   |   161 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@             |   346 node`ssleay_rand_add+0x367
    131072 |@@@                     |    97 node`ssl23_accept+0x2f
    262144 |                        |    24 
    524288 |                        |     8 
   1048576 |                        |     2 
   2097152 |                        |     3 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  576   109468 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    37 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |@                       |    32 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |   115 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |   242 node`ssleay_rand_add+0xcb
    131072 |@@@@                    |   115 node`ssl23_accept+0x2f
    262144 |                        |    17 
    524288 |                        |     4 
   1048576 |                        |    10 
   2097152 |                        |     3 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  122   500987 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    17 node`uv_mutex_lock+0x9
     16384 |@@@@@@@                 |    38 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@                     |    16 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@                      |    15 node`uv__thread_start+0x22
    131072 |@@@                     |    17 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |     6 
    524288 |                        |     3 
   1048576 |                        |     1 
   2097152 |                        |     3 
   4194304 |                        |     3 
   8388608 |                        |     2 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  440   134832 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |    18 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |   108 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   122 node`ssleay_rand_add+0x367
     65536 |@@@@@@                  |   127 node`ssl3_accept+0x31
    131072 |@                       |    28 node`ssl3_read_bytes+0x17a
    262144 |                        |    14 
    524288 |                        |     8 
   1048576 |                        |    10 
   2097152 |                        |     1 
   4194304 |                        |     3 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1036    50757 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |   135 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   316 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |   253 node`ssleay_rand_bytes+0x7a
     65536 |@@@@@                   |   248 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |    58 node`def_generate_session_id+0x28
    262144 |                        |    12 
    524288 |                        |    11 
   1048576 |                        |     1 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1031    50979 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    80 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@                |   362 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   291 node`ssleay_rand_bytes+0x40a
     65536 |@@@@                    |   210 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |    63 node`ssl3_get_client_hello+0x56d
    262144 |                        |    13 
    524288 |                        |     5 
   1048576 |                        |     6 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  915    57048 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    72 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   298 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   260 node`ssleay_rand_bytes+0x40a
     65536 |@@@@@                   |   199 node`ssleay_rand_pseudo_bytes+0xe
    131072 |@                       |    72 node`def_generate_session_id+0x28
    262144 |                        |     8 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     1 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  739    68163 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     9 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |   112 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |   307 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@                  |   206 node`ssl3_accept+0x31
    131072 |@@                      |    82 node`ssl23_get_client_hello+0x660
    262144 |                        |    12 
    524288 |                        |     5 
   1048576 |                        |     4 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  891    55780 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    75 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |   288 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |   254 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |   218 node`ssl3_accept+0x31
    131072 |                        |    32 node`ssl23_get_client_hello+0x660
    262144 |                        |    15 
    524288 |                        |     2 
   1048576 |                        |     4 
   2097152 |                        |     2 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  666    71513 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    40 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |    79 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@                |   242 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   219 node`SSL_free+0x65
    131072 |@@                      |    57 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    262144 |                        |    16 
    524288 |                        |     7 
   1048576 |                        |     4 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  321   137605 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     8 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |    26 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |   119 node`ssleay_rand_add+0x3d7
     65536 |@@@@@@@                 |    95 node`ssl3_accept+0x31
    131072 |@@@                     |    42 node`ssl3_read_bytes+0x17a
    262144 |                        |    11 
    524288 |                        |    10 
   1048576 |                        |     3 
   2097152 |                        |     6 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  112   334701 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    14 node`uv_mutex_lock+0x9
     16384 |@@@@@@@                 |    37 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@                     |    14 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@                      |    10 node`uv__thread_start+0x22
    131072 |@@@                     |    16 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |     6 
    524288 |@                       |     9 
   1048576 |                        |     2 
   2097152 |                        |     2 
   4194304 |                        |     1 
   8388608 |                        |     0 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  617    60264 0x103000198                  libSystem.B.dylib`pthread_rwlock_rdlock+0xa0

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |    39 libSystem.B.dylib`pthread_rwlock_rdlock+0xa0
     16384 |@@                      |    64 node`uv_rwlock_rdlock+0x9
     32768 |@@@@@@@@@               |   245 node`int_free_ex_data+0x44
     65536 |@@@@@@@                 |   180 node`SSL_SESSION_free+0x54
    131072 |@@                      |    76 node`SSL_free+0xfe
    262144 |                        |     7 
    524288 |                        |     4 
   1048576 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  116   297524 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@                    |    23 node`uv_mutex_lock+0x9
     16384 |@@@@@@                  |    31 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@                      |    12 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@@                     |    16 node`uv__thread_start+0x22
    131072 |@@                      |    11 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@                       |     8 
    524288 |                        |     3 
   1048576 |                        |     2 
   2097152 |@                       |     8 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  166   194979 0x103000260                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    27 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |    38 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |    30 node`CRYPTO_add_lock+0x64
     65536 |@@@@@                   |    36 node`ssl_cert_dup+0x1cb
    131072 |@@                      |    17 node`SSL_new+0xc6
    262144 |                        |     5 
    524288 |@                       |     7 
   1048576 |                        |     2 
   2097152 |                        |     1 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  149   207384 0x103000260                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@                     |    23 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |    41 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@                 |    49 node`ssl_cert_dup+0x1cb
    131072 |@@                      |    14 node`SSL_new+0xc6
    262144 |                        |     4 
    524288 |@                       |     8 
   1048576 |                        |     4 
   2097152 |                        |     3 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   61   459557 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |    31 node`uv_mutex_lock+0x9
     32768 |@@@@                    |    12 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@                     |     8 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
    131072 |@                       |     3 0x59fa660c259
    262144 |                        |     2 0x59fa661b58d
    524288 |                        |     1 
   1048576 |                        |     0 
   2097152 |                        |     2 
   4194304 |                        |     1 
   8388608 |                        |     0 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  111   212253 0x103000260                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     4 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@                    |    20 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@@               |    42 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@                   |    27 node`asn1_item_combine_free+0x1bf
    131072 |@@                      |    11 node`ASN1_item_free+0x17
    262144 |                        |     1 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |                        |     2 
   4194304 |                        |     1 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  171   127574 0x103000260                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@@                 |    51 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |    32 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |    33 node`CRYPTO_add_lock+0x64
     65536 |@@@                     |    24 node`asn1_item_combine_free+0x1bf
    131072 |@@                      |    19 node`ASN1_item_free+0x17
    262144 |                        |     4 
    524288 |                        |     4 
   1048576 |                        |     2 
   2097152 |                        |     1 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   46   435600 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     2 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@                |    16 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@                  |    13 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
     65536 |@@@                     |     7 0x59fa660c259
    131072 |@                       |     2 0x59fa661b58d
    262144 |@                       |     3 
    524288 |@                       |     2 
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |                        |     0 
   8388608 |                        |     0 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  140   141136 0x103000260                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    22 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@                      |    17 node`uv_rwlock_wrlock+0x9
     32768 |@@@                     |    19 node`CRYPTO_add_lock+0x64
     65536 |@@@@@@                  |    39 node`X509_verify_cert+0xec
    131072 |@@@@@                   |    33 node`ssl3_output_cert_chain+0x103
    262144 |                        |     3 
    524288 |                        |     3 
   1048576 |                        |     1 
   2097152 |                        |     2 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   69   286126 0x103001070                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@                  |    20 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |     8 node`CRYPTO_add_lock+0x64
     65536 |@@@@                    |    14 node`BIO_free+0x33
    131072 |@                       |     5 node`ssl_free_wbio_buffer+0x2d
    262144 |@@@                     |    11 
    524288 |@@                      |     6 
   1048576 |                        |     1 
   2097152 |                        |     1 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   61   301223 0x103001070                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |     3 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |    17 node`CRYPTO_add_lock+0x7d
     65536 |@@@@                    |    11 node`BIO_free+0x33
    131072 |@@@                     |     8 node`ssl_free_wbio_buffer+0x2d
    262144 |@                       |     5 
    524288 |@@@                     |     8 
   1048576 |@@                      |     6 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  115   136343 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@                   |    24 node`uv_mutex_lock+0x9
     16384 |@@@@@@                  |    33 tlsnappy.node`tlsnappy::Context::RunLoop()+0x35
     32768 |@@@                     |    16 tlsnappy.node`tlsnappy::Context::Loop(void*)+0x14
     65536 |@@@                     |    16 node`uv__thread_start+0x22
    131072 |@@                      |    10 libSystem.B.dylib`_pthread_start+0x14b
    262144 |@@                      |    10 
    524288 |                        |     2 
   1048576 |                        |     2 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   49   268998 0x103001070                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@                       |     4 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@                   |    12 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@@@               |    20 node`BIO_free+0x33
    131072 |@@@                     |     7 node`BIO_free_all+0x15
    262144 |                        |     2 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |                        |     0 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   74   163286 0x103001070                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |    11 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |    24 node`uv_rwlock_wrlock+0x9
     32768 |@                       |     4 node`CRYPTO_add_lock+0x64
     65536 |@@@@                    |    15 node`BIO_free+0x33
    131072 |@@@                     |    10 node`ssl3_digest_cached_records+0x186
    262144 |@                       |     5 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   51   230339 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@            |    26 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@                     |     7 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
     65536 |@@@                     |     7 0x59fa660c259
    131072 |                        |     1 0x59fa661b58d
    262144 |                        |     2 
    524288 |                        |     1 
   1048576 |                        |     1 
   2097152 |@                       |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   99   112288 0x103001070                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |    11 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@                 |    29 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@                   |    22 node`CRYPTO_add_lock+0x64
     65536 |@@@                     |    16 node`BIO_free+0x33
    131072 |@@                      |     9 node`BIO_free_all+0x15
    262144 |@                       |     5 
    524288 |                        |     4 
   1048576 |                        |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   15   734003 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@        |    10 node`uv_mutex_lock+0x9
     32768 |@                       |     1 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@                       |     1 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |                        |     0 node`uv__async_io+0x98
    262144 |@                       |     1 node`ev_invoke_pending+0x4f
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |@                       |     1 
   4194304 |                        |     0 
   8388608 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   44   233658 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |     7 node`uv_mutex_lock+0x9
     16384 |@@@@@@@                 |    14 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@@                 |    13 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |@@@                     |     6 0x59fa6615579
    131072 |                        |     0 0x59fa662bce4
    262144 |@                       |     3 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   25   376176 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@             |    12 node`uv_mutex_lock+0x9
     32768 |@@@@                    |     5 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@                     |     4 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |                        |     1 node`uv__async_io+0x98
    262144 |                        |     1 node`ev_invoke_pending+0x4f
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |@                       |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   79   118109 0x103000260                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |     7 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |    29 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@@@                 |    26 node`X509_verify_cert+0xec
    131072 |@@@                     |    10 node`ssl3_output_cert_chain+0x103
    262144 |@                       |     4 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   51   178938 0x103000260                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     32768 |@@@@@                   |    12 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     65536 |@@@@@@@@@               |    21 node`uv_rwlock_wrlock+0x9
    131072 |@@@@@                   |    12 node`CRYPTO_add_lock+0x64
    262144 |                        |     2 node`asn1_item_combine_free+0x1bf
    524288 |                        |     0 
   1048576 |                        |     1 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   48   170666 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     2 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@               |    19 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@@@@                |    16 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
     65536 |@@@                     |     6 0x59fa660c259
    131072 |                        |     1 0x59fa661b58d
    262144 |@                       |     2 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     1 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   52   155332 0x103001070                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@                      |     6 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@@@                |    19 node`CRYPTO_add_lock+0x7d
     65536 |@@@@@                   |    12 node`BIO_free+0x33
    131072 |@@                      |     6 node`ssl3_digest_cached_records+0x186
    262144 |@                       |     4 
    524288 |                        |     1 
   1048576 |                        |     0 
   2097152 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   41   173430 0x103001070                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     16384 |@@                      |     4 libSystem.B.dylib`_pthread_cond_wait+0x586
     32768 |@@@@@                   |     9 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     65536 |@@@@@@@@                |    15 node`uv_rwlock_wrlock+0x9
    131072 |@@@                     |     6 node`CRYPTO_add_lock+0x64
    262144 |@                       |     3 node`BIO_free+0x33
    524288 |@                       |     2 
   1048576 |                        |     1 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   39   155858 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     4 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@             |    19 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@                       |     3 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@@                      |     4 0x59fa63fc879
    131072 |@                       |     3 0x59fa63f489a
    262144 |@                       |     3 
    524288 |                        |     0 
   1048576 |@                       |     2 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   37   156312 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |     6 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@            |    20 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@                       |     3 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@                       |     3 0x59fa63fc879
    131072 |                        |     1 0x59fa63f489a
    262144 |                        |     1 
    524288 |                        |     1 
   1048576 |                        |     0 
   2097152 |@                       |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   29   188698 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@                    |     6 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@              |    13 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@                      |     3 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@                       |     2 0x59fa63fc879
    131072 |@                       |     2 0x59fa63f489a
    262144 |@                       |     2 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   27   185381 0x103000260                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@                     |     4 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |    12 node`CRYPTO_add_lock+0x64
    131072 |@@@@                    |     5 node`X509_verify_cert+0xec
    262144 |                        |     1 
    524288 |@                       |     2 
   1048576 |                        |     0 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   46    95988 0x103000260                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@@@                    |     8 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@              |    21 node`CRYPTO_add_lock+0x64
    131072 |@@@@@                   |    11 node`ssl_cert_dup+0x1cb
    262144 |@                       |     3 
    524288 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   29   148585 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |    15 node`uv_mutex_lock+0x9
     32768 |@                       |     2 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@                    |     5 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
    131072 |@                       |     2 0x59fa6615579
    262144 |@@                      |     3 0x59fa662bce4
    524288 |                        |     1 
   1048576 |                        |     0 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   41   104697 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |     6 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@               |    17 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@                    |     7 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |@                       |     3 0x59fa6615579
    131072 |@                       |     3 0x59fa662bce4
    262144 |@@                      |     4 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   44    88250 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     4 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@              |    19 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@@@@                   |    10 tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
     65536 |@@@                     |     7 0x59fa6615579
    131072 |                        |     1 0x59fa662bce4
    262144 |@                       |     2 
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   17   172513 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@                       |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@@               |     7 node`uv_rwlock_wrunlock+0x9
     65536 |@@@@@@@@@               |     7 node`ssleay_rand_add+0x1cf
    131072 |@                       |     1 node`bnrand+0xbc
    262144 |                        |     0 node`bn_rand_range+0x13c
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   21   134192 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@           |    12 node`uv_mutex_lock+0x9
     32768 |@@@@@@                  |     6 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@                       |     1 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |                        |     0 node`uv__async_io+0x98
    262144 |@                       |     1 node`ev_invoke_pending+0x4f
    524288 |                        |     0 
   1048576 |                        |     0 
   2097152 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   10   262144 0x1030008a0                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@                    |     2 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@                 |     3 node`uv_rwlock_wrunlock+0x9
     65536 |@@@@                    |     2 node`X509_STORE_get_by_subject+0x6c
    131072 |                        |     0 node`X509_STORE_CTX_get1_issuer+0x48
    262144 |@@                      |     1 node`X509_verify_cert+0x2a9
    524288 |                        |     0 
   1048576 |@@@@                    |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   31    83241 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
      8192 |                        |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     16384 |@@@@@@                  |     9 node`uv_rwlock_wrunlock+0x9
     32768 |@@@@@@                  |     8 node`ssleay_rand_bytes+0x452
     65536 |@@@@@                   |     7 node`bnrand+0xe0
    131072 |@@                      |     3 node`bn_rand_range+0x13c
    262144 |                        |     1 
    524288 |@                       |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2  1179648 0x103000a30                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
    262144 |@@@@@@@@@@@@            |     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
    524288 |                        |     0 node`uv_rwlock_wrunlock+0x9
   1048576 |                        |     0 node`CRYPTO_add_lock+0x7d
   2097152 |@@@@@@@@@@@@            |     1 node`ssl_cert_free+0x36
                                            node`SSL_free+0x14f
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   21   110396 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |     3 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@                    |     4 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@                  |     6 node`ssleay_rand_add+0x367
     65536 |@@@@@                   |     5 node`bnrand+0xbc
    131072 |@                       |     1 node`bn_rand_range+0x13c
    262144 |                        |     0 
    524288 |@                       |     1 
   1048576 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   15   139810 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@               |     6 node`uv_mutex_lock+0x9
     32768 |@@@@                    |     3 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@                       |     1 tlsnappy.node`tlsnappy::Socket::EmitEvent(uv_async_s*, int)+0xc3
    131072 |@@@                     |     2 node`uv__async_io+0x98
    262144 |@@@                     |     2 node`ev_invoke_pending+0x4f
    524288 |                        |     0 
   1048576 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   37    49373 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@                       |     3 node`uv_mutex_lock+0x9
     16384 |@@@@@@@@@@@@@@          |    22 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     32768 |@@                      |     4 tlsnappy.node`tlsnappy::Socket::EncIn(v8::Arguments const&)+0xa3
     65536 |@                       |     2 0x59fa63fc879
    131072 |@@@                     |     5 0x59fa63f489a
    262144 |                        |     0 
    524288 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   12   118101 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     16384 |                        |     0 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     32768 |@@                      |     1 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@@@@@@@@          |     7 node`ssleay_rand_add+0xcb
    131072 |@@                      |     1 node`bnrand+0xbc
    262144 |@@                      |     1 
    524288 |@@                      |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   18    70087 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@                      |     2 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@                   |     4 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@@                |     6 node`ssleay_rand_add+0xcb
     65536 |@@@@                    |     3 node`bnrand+0xbc
    131072 |@@                      |     2 node`bn_rand_range+0x13c
    262144 |                        |     0 
    524288 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    4   290816 0x103000a30                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@                  |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     32768 |@@@@@@                  |     1 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@                  |     1 node`CRYPTO_add_lock+0x64
    131072 |                        |     0 node`ssl_cert_free+0x36
    262144 |                        |     0 node`SSL_free+0x14f
    524288 |                        |     0 
   1048576 |@@@@@@                  |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   21    49152 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@@@                     |     3 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@@@@             |    10 node`uv_rwlock_wrunlock+0x9
     65536 |@@@@@@                  |     6 node`ssleay_rand_add+0x3d7
    131072 |@@                      |     2 node`bnrand+0xbc
                                            node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   10    65536 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@               |     4 libSystem.B.dylib`_pthread_cond_wait+0x586
     65536 |@@@@@@@@@               |     4 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
    131072 |@@@@                    |     2 node`uv_rwlock_wrlock+0x9
                                            node`ssleay_rand_bytes+0x40a
                                            node`bnrand+0xe0
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   10    49152 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@                    |     2 libSystem.B.dylib`_pthread_cond_wait+0x586
     32768 |@@@@                    |     2 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
     65536 |@@@@@@@@@@@@@@          |     6 node`uv_rwlock_wrlock+0x9
                                            node`ssleay_rand_add+0x367
                                            node`bnrand+0xbc
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   19    24576 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@@@                |     7 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@                  |     5 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@                 |     6 node`ssleay_rand_bytes+0x40a
     65536 |                        |     0 node`bnrand+0xe0
    131072 |@                       |     1 node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    7    43300 0x103000e18                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@                     |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |                        |     0 node`uv_rwlock_wrlock+0x9
     32768 |@@@@@@@@@@              |     3 node`ssleay_rand_bytes+0x7a
     65536 |@@@@@@@@@@              |     3 node`bnrand+0xe0
                                            node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    8    30720 0x103000e18                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@               |     3 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
     32768 |@@@@@@@@@@@@            |     4 node`uv_rwlock_wrunlock+0x9
     65536 |@@@                     |     1 node`ssleay_rand_bytes+0x235
                                            node`bnrand+0xe0
                                            node`bn_rand_range+0x13c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    3    54613 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@                |     1 node`uv_mutex_lock+0x9
     65536 |@@@@@@@@@@@@@@@@        |     2 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x59fa6512f79
                                            0x59fa652b9ed
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
                                            node`uv_rwlock_rdunlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x60
                                            node`RSA_eay_mod_exp+0x137
                                            node`RSA_eay_private_decrypt+0x22e
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    49152 0x103000e18                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@            |     1 libSystem.B.dylib`_pthread_cond_wait+0x586
     65536 |@@@@@@@@@@@@            |     1 libSystem.B.dylib`pthread_rwlock_wrlock+0x119
                                            node`uv_rwlock_wrlock+0x9
                                            node`ssleay_rand_bytes+0x7a
                                            node`bnrand+0xe0
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    6    16384 0x1030008a0                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@@@                |     2 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
     16384 |@@@@@@@@@@@@            |     3 node`uv_rwlock_wrlock+0x9
     32768 |@@@@                    |     1 node`X509_STORE_get_by_subject+0x3d
                                            node`X509_STORE_CTX_get1_issuer+0x48
                                            node`X509_verify_cert+0x2a9
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    40960 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |     1 node`uv_mutex_lock+0x9
     32768 |                        |     0 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@@@@@@@@            |     1 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x59fa6512f79
                                            0x59fa652b9ed
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    40960 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@            |     1 node`uv_mutex_lock+0x9
     32768 |                        |     0 tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
     65536 |@@@@@@@@@@@@            |     1 tlsnappy.node`tlsnappy::Socket::ClearIn(v8::Arguments const&)+0x94
                                            0x59fa6512f79
                                            0x59fa652b9ed
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x103000710                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
                                            node`uv_rwlock_wrlock+0x9
                                            node`rsa_get_blinding+0x88
                                            node`RSA_eay_private_decrypt+0x179
                                            node`ssl3_get_client_key_exchange+0x159
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x103000710                  libSystem.B.dylib`pthread_rwlock_wrlock+0xa1

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_wrlock+0xa1
                                            node`uv_rwlock_wrlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x79
                                            node`RSA_eay_mod_exp+0x137
                                            node`RSA_eay_private_decrypt+0x22e
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x103000710                  libSystem.B.dylib`pthread_rwlock_unlock+0x6e

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`pthread_rwlock_unlock+0x6e
                                            node`uv_rwlock_rdunlock+0x9
                                            node`rsa_get_blinding+0x6d
                                            node`RSA_eay_private_decrypt+0x179
                                            node`ssl3_get_client_key_exchange+0x159
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x103000710                  libSystem.B.dylib`_pthread_cond_wait+0x586

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 libSystem.B.dylib`_pthread_cond_wait+0x586
                                            libSystem.B.dylib`pthread_rwlock_rdlock+0x103
                                            node`uv_rwlock_rdlock+0x9
                                            node`rsa_get_blinding+0x41
                                            node`RSA_eay_private_decrypt+0x179
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x101806008                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x59fa651eb99
                                            0x59fa654b484
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2    32768 0x101803f38                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@@@@@@@@@@@@@@@@@@@@@@@|     2 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x59fa651eb99
                                            0x59fa654b484
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    16384 0x1018004b8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x59fa651eb99
                                            0x59fa654b484
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1     8192 0x101802ab8                  node`uv_mutex_lock+0x9

      nsec ---- Time Distribution --- count Stack
      8192 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_mutex_lock+0x9
                                            tlsnappy.node`tlsnappy::Context::Enqueue(tlsnappy::Socket*)+0x3c
                                            tlsnappy.node`tlsnappy::Socket::Close(v8::Arguments const&)+0x42
                                            0x59fa651eb99
                                            0x59fa654b484

R/W reader block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7825  1074987 0x1030000c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    83 node`uv_rwlock_rdlock+0x9
     65536 |@                       |   462 node`int_thread_get_item+0x46
    131072 |@@@@@                   |  1879 node`ERR_get_state+0x47
    262144 |@@@@@@                  |  1989 node`get_error_values+0x33
    524288 |@@@                     |  1121 node`SSL_get_error+0x24
   1048576 |@@                      |   738 
   2097152 |@@                      |   774 
   4194304 |@                       |   539 
   8388608 |                        |   200 
  16777216 |                        |    39 
  33554432 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 7938   477835 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    77 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   907 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@               |  3182 node`SSL_new+0x31f
    262144 |@@@@@@@                 |  2374 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
    524288 |@                       |   586 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x4b
   1048576 |                        |   288 
   2097152 |                        |   265 
   4194304 |                        |   178 
   8388608 |                        |    69 
  16777216 |                        |    12 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6857   441237 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   103 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   795 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@                |  2374 node`BIO_set+0x91
    262144 |@@@@@@@@                |  2457 node`BIO_new+0x5f
    524288 |@@                      |   585 tlsnappy.node`tlsnappy::Socket::Socket(tlsnappy::Context*)+0xc6
   1048576 |                        |   173 
   2097152 |                        |   184 
   4194304 |                        |   120 
   8388608 |                        |    56 
  16777216 |                        |    10 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3484   832000 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    29 node`uv_rwlock_rdlock+0x9
     65536 |@                       |   260 node`int_free_ex_data+0x44
    131072 |@@@@@@@                 |  1090 node`BIO_free+0x69
    262144 |@@@@@@                  |   962 node`ssl_free_wbio_buffer+0x2d
    524288 |@@                      |   413 node`ssl3_accept+0xb53
   1048576 |@                       |   264 
   2097152 |@                       |   226 
   4194304 |@                       |   152 
   8388608 |                        |    73 
  16777216 |                        |    14 
  33554432 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2670  1013108 0x1030000c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    30 node`uv_rwlock_rdlock+0x9
     65536 |@                       |   196 node`int_thread_get_item+0x46
    131072 |@@@@@@                  |   712 node`ERR_get_state+0x47
    262144 |@@@@@@                  |   696 node`ERR_clear_error+0xc
    524288 |@@@                     |   373 node`ssl3_accept+0x36
   1048576 |@@                      |   227 
   2097152 |@                       |   187 
   4194304 |@                       |   155 
   8388608 |                        |    80 
  16777216 |                        |    12 
  33554432 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6864   383348 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    75 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   929 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@@              |  3048 node`BIO_free+0x69
    262144 |@@@@@@                  |  1964 node`ssl3_digest_cached_records+0x186
    524288 |@                       |   386 node`ssl3_get_client_hello+0xa0d
   1048576 |                        |   166 
   2097152 |                        |   143 
   4194304 |                        |   101 
   8388608 |                        |    42 
  16777216 |                        |     8 
  33554432 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6817   381607 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    73 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   830 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@              |  2862 node`BIO_set+0x91
    262144 |@@@@@@@                 |  2104 node`BIO_new+0x5f
    524288 |@                       |   448 node`ssl3_init_finished_mac+0x51
   1048576 |                        |   185 
   2097152 |                        |   165 
   4194304 |                        |   107 
   8388608 |                        |    39 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6292   381404 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    68 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   808 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@@              |  2738 node`X509_STORE_CTX_cleanup+0x96
    262144 |@@@@@@@                 |  1843 node`ssl3_output_cert_chain+0x15f
    524288 |@                       |   396 node`ssl3_send_server_certificate+0x48
   1048576 |                        |   165 
   2097152 |                        |   135 
   4194304 |                        |    88 
   8388608 |                        |    46 
  16777216 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6460   355284 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    84 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   841 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@              |  2853 node`SSL_SESSION_new+0xf7
    262144 |@@@@@@                  |  1870 node`ssl_get_new_session+0x33
    524288 |@                       |   373 node`ssl3_get_client_hello+0x23b
   1048576 |                        |   197 
   2097152 |                        |   123 
   4194304 |                        |    78 
   8388608 |                        |    36 
  16777216 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5962   375958 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    58 node`uv_rwlock_rdlock+0x9
     65536 |@@@                     |   751 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@@             |  2769 node`X509_STORE_CTX_init+0x2ca
    262144 |@@@@@@                  |  1667 node`ssl3_output_cert_chain+0xcd
    524288 |@                       |   330 node`ssl3_send_server_certificate+0x48
   1048576 |                        |   143 
   2097152 |                        |   121 
   4194304 |                        |    76 
   8388608 |                        |    37 
  16777216 |                        |     9 
  33554432 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6066   357909 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    54 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   699 node`int_new_ex_data+0x4d
    131072 |@@@@@@@@@@              |  2697 node`BIO_set+0x91
    262144 |@@@@@@@                 |  1874 node`BIO_new+0x5f
    524288 |@                       |   343 node`ssl_init_wbio_buffer+0x30
   1048576 |                        |   152 
   2097152 |                        |   134 
   4194304 |                        |    73 
   8388608 |                        |    38 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5623   374903 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_rdlock+0x9
     32768 |                        |   111 node`int_new_ex_data+0x4d
     65536 |@@@                     |   705 node`BIO_set+0x91
    131072 |@@@@@@@@                |  2043 node`BIO_new+0x5f
    262144 |@@@@@@@@                |  1944 tlsnappy.node`tlsnappy::Socket::Socket(tlsnappy::Context*)+0xdb
    524288 |@                       |   449 
   1048576 |                        |   143 
   2097152 |                        |   107 
   4194304 |                        |    82 
   8388608 |                        |    37 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1753   926644 0x1030000c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    15 node`uv_rwlock_rdlock+0x9
     65536 |@                       |    93 node`int_thread_get_item+0x46
    131072 |@@@@@@                  |   465 node`ERR_get_state+0x47
    262144 |@@@@@@                  |   469 node`ERR_clear_error+0xc
    524288 |@@@                     |   265 node`ssl23_accept+0x34
   1048576 |@@                      |   161 
   2097152 |@                       |   145 
   4194304 |@                       |    96 
   8388608 |                        |    38 
  16777216 |                        |     6 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3052   528088 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    40 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   349 node`int_free_ex_data+0x44
    131072 |@@@@@@@@                |  1060 node`SSL_free+0x65
    262144 |@@@@@@                  |   890 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
    524288 |@@                      |   318 tlsnappy.node`tlsnappy::Context::RunLoop()+0x8a
   1048576 |@                       |   164 
   2097152 |                        |   124 
   4194304 |                        |    75 
   8388608 |                        |    28 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1712   863509 0x1030000c8                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    21 node`uv_rwlock_rdlock+0x9
     65536 |@                       |   121 node`int_thread_get_item+0x46
    131072 |@@@@@@@                 |   501 node`ERR_get_state+0x47
    262144 |@@@@@@                  |   492 node`ERR_clear_error+0xc
    524288 |@@                      |   198 node`ssl3_output_cert_chain+0x108
   1048576 |@                       |   121 
   2097152 |@                       |   114 
   4194304 |@                       |   100 
   8388608 |                        |    42 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2185   493919 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    35 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   244 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@               |   883 node`BIO_free+0x69
    262144 |@@@@@@                  |   608 node`BIO_free_all+0x15
    524288 |@                       |   177 node`SSL_free+0x9c
   1048576 |                        |    80 
   2097152 |                        |    85 
   4194304 |                        |    45 
   8388608 |                        |    27 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1958   424695 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    31 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   241 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@               |   806 node`BIO_free+0x69
    262144 |@@@@@@                  |   567 node`BIO_free_all+0x15
    524288 |@                       |   135 node`SSL_free+0xb0
   1048576 |                        |    57 
   2097152 |                        |    63 
   4194304 |                        |    47 
   8388608 |                        |    10 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1848   397577 0x103000190                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    22 node`uv_rwlock_rdlock+0x9
     65536 |@@                      |   226 node`int_free_ex_data+0x44
    131072 |@@@@@@@@@@              |   789 node`SSL_SESSION_free+0x54
    262144 |@@@@@@                  |   525 node`SSL_free+0xfe
    524288 |@                       |   116 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
   1048576 |@                       |    82 
   2097152 |                        |    50 
   4194304 |                        |    24 
   8388608 |                        |    13 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    6  3844778 0x103000708                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
    524288 |@@@@@@@@                |     2 node`uv_rwlock_rdlock+0x9
   1048576 |@@@@                    |     1 node`rsa_get_blinding+0x41
   2097152 |                        |     0 node`RSA_eay_private_decrypt+0x179
   4194304 |@@@@                    |     1 node`ssl3_get_client_key_exchange+0x159
   8388608 |@@@@@@@@                |     2 node`ssl3_accept+0x83f
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    2  9437184 0x103000708                  node`uv_rwlock_rdlock+0x9

      nsec ---- Time Distribution --- count Stack
   2097152 |@@@@@@@@@@@@            |     1 node`uv_rwlock_rdlock+0x9
   4194304 |                        |     0 node`BN_MONT_CTX_set_locked+0x3e
   8388608 |                        |     0 node`RSA_eay_mod_exp+0x157
  16777216 |@@@@@@@@@@@@            |     1 node`RSA_eay_private_decrypt+0x22e
                                            node`ssl3_get_client_key_exchange+0x159

R/W writer block

-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
61863   534771 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   514 node`uv_rwlock_wrlock+0x9
     65536 |@                       |  3993 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@@             | 28635 node`EVP_PKEY_free+0x31
    262144 |@@@@@@                  | 15952 node`EVP_PKEY_CTX_free+0x32
    524288 |@                       |  5114 node`EVP_MD_CTX_cleanup+0x80
   1048576 |@                       |  2700 
   2097152 |@                       |  2616 
   4194304 |                        |  1617 
   8388608 |                        |   609 
  16777216 |                        |   108 
  33554432 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
30620   565504 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   211 node`uv_rwlock_wrlock+0x9
     65536 |@                       |  1866 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@              | 13689 node`EVP_PKEY_CTX_dup+0xb4
    262144 |@@@@@@                  |  8037 node`EVP_MD_CTX_copy_ex+0x13c
    524288 |@@                      |  2680 node`EVP_DigestSignFinal+0x6c
   1048576 |@                       |  1500 
   2097152 |@                       |  1381 
   4194304 |                        |   887 
   8388608 |                        |   302 
  16777216 |                        |    65 
  33554432 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
25205   613139 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |   224 node`uv_rwlock_wrlock+0x9
     65536 |@                       |  1596 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@              | 10754 node`EVP_PKEY_CTX_dup+0xb4
    262144 |@@@@@@                  |  6537 node`EVP_MD_CTX_copy_ex+0x13c
    524288 |@@                      |  2274 node`tls1_mac+0x10b
   1048576 |@                       |  1368 
   2097152 |@                       |  1290 
   4194304 |                        |   814 
   8388608 |                        |   286 
  16777216 |                        |    60 
  33554432 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8183   908438 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    34 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   441 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@                |  3002 node`int_ctx_new+0x14f
    262144 |@@@@@                   |  1996 node`do_sigver_init+0x41
    524288 |@@                      |   885 node`tls1_change_cipher_state+0x482
   1048576 |@                       |   562 
   2097152 |@                       |   615 
   4194304 |@                       |   406 
   8388608 |                        |   195 
  16777216 |                        |    46 
  33554432 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 8157   742182 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    39 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   401 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@               |  3206 node`EVP_PKEY_free+0x31
    262144 |@@@@@@                  |  2158 node`tls1_change_cipher_state+0x48a
    524288 |@@                      |   832 node`ssl3_do_change_cipher_spec+0x95
   1048576 |@                       |   535 
   2097152 |@                       |   494 
   4194304 |                        |   337 
   8388608 |                        |   124 
  16777216 |                        |    29 
  33554432 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5413   593171 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    19 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   364 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@              |  2434 node`EVP_PKEY_free+0x31
    262144 |@@@@@                   |  1348 node`tls1_change_cipher_state+0x48a
    524288 |@@                      |   477 node`ssl3_accept+0xa94
   1048576 |@                       |   255 
   2097152 |@                       |   276 
   4194304 |                        |   164 
   8388608 |                        |    65 
  16777216 |                        |    11 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3056   847003 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    15 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   151 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@               |  1193 node`X509_PUBKEY_get+0x45
    262144 |@@@@@                   |   736 node`X509_get_pubkey_parameters+0x44
    524288 |@@                      |   321 node`X509_verify_cert+0x93c
   1048576 |@                       |   209 
   2097152 |@                       |   202 
   4194304 |@                       |   150 
   8388608 |                        |    64 
  16777216 |                        |    15 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4009   630209 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    23 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   236 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@              |  1794 node`EVP_PKEY_free+0x31
    262144 |@@@@@                   |   971 node`X509_get_pubkey_parameters+0xd6
    524288 |@@                      |   386 node`X509_verify_cert+0x93c
   1048576 |@                       |   204 
   2097152 |@                       |   207 
   4194304 |                        |   123 
   8388608 |                        |    52 
  16777216 |                        |    13 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
18980   126003 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |  1556 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |  5968 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  9883 node`int_new_ex_data+0x1d
    262144 |@                       |  1295 node`BIO_set+0x91
    524288 |                        |   148 node`BIO_new+0x5f
   1048576 |                        |    78 
   2097152 |                        |    40 
   4194304 |                        |     9 
   8388608 |                        |     2 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3487   643575 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    22 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   174 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@               |  1391 node`ssl_cert_dup+0x1fa
    262144 |@@@@@@                  |   971 node`SSL_new+0xc6
    524288 |@@                      |   366 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
   1048576 |@                       |   213 
   2097152 |@                       |   180 
   4194304 |                        |   119 
   8388608 |                        |    42 
  16777216 |                        |     9 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 3818   547821 0x1030007d0                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    22 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   236 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@@             |  1778 node`EVP_PKEY_free+0x31
    262144 |@@@@@@                  |   964 node`ssl_cert_free+0x87
    524288 |@                       |   310 node`SSL_free+0x14f
   1048576 |@                       |   195 
   2097152 |@                       |   167 
   4194304 |                        |    94 
   8388608 |                        |    47 
  16777216 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1494   718417 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    39 node`uv_rwlock_wrlock+0x9
     65536 |@                       |   106 node`ssleay_rand_add+0xcb
    131072 |@@@@@@@@                |   560 node`ssl23_accept+0x2f
    262144 |@@@@@@                  |   377 node`ssl23_read+0x4e
    524288 |@@                      |   151 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x116
   1048576 |@                       |    90 
   2097152 |@                       |    75 
   4194304 |@                       |    64 
   8388608 |                        |    29 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5165   205613 0x1030000c8                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |   503 node`int_thread_get+0x26
     65536 |@@@@@@                  |  1307 node`int_thread_get_item+0x1f
    131072 |@@@@@@@@@@              |  2181 node`ERR_get_state+0x47
    262144 |@@@                     |   769 node`get_error_values+0x33
    524288 |                        |   215 
   1048576 |                        |    97 
   2097152 |                        |    67 
   4194304 |                        |    22 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1716   535497 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    53 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   151 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@              |   750 node`ssl23_accept+0x2f
    262144 |@@@@@@                  |   438 node`ssl23_read+0x4e
    524288 |@                       |   126 tlsnappy.node`tlsnappy::Socket::OnEvent()+0x116
   1048576 |                        |    61 
   2097152 |                        |    71 
   4194304 |                        |    41 
   8388608 |                        |    21 
  16777216 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6233   142259 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |   500 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@                  |  1630 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@@           |  3443 node`int_new_ex_data+0x1d
    262144 |@                       |   513 node`SSL_new+0x31f
    524288 |                        |    81 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
   1048576 |                        |    33 
   2097152 |                        |    22 
   4194304 |                        |     9 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4560   186098 0x1030000c8                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@@                      |   461 node`int_thread_get+0x26
     65536 |@@@@@@                  |  1150 node`int_thread_get_item+0x1f
    131072 |@@@@@@@@@@              |  2024 node`ERR_get_state+0x47
    262144 |@@@                     |   658 node`ERR_clear_error+0xc
    524288 |                        |   143 
   1048576 |                        |    66 
   2097152 |                        |    40 
   4194304 |                        |    12 
   8388608 |                        |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6539   128583 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     16384 |                        |     1 node`uv_rwlock_wrlock+0x9
     32768 |@                       |   487 node`def_get_class+0x4f
     65536 |@@@@@@@                 |  2038 node`int_new_ex_data+0x1d
    131072 |@@@@@@@@@@@@            |  3448 node`SSL_SESSION_new+0xf7
    262144 |@                       |   469 node`ssl_get_new_session+0x33
    524288 |                        |    48 
   1048576 |                        |    31 
   2097152 |                        |    12 
   4194304 |                        |     2 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6556   126633 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |   478 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |  2113 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  3394 node`int_free_ex_data+0x1d
    262144 |@                       |   482 node`X509_STORE_CTX_cleanup+0x96
    524288 |                        |    50 node`ssl3_output_cert_chain+0x15f
   1048576 |                        |    23 
   2097152 |                        |    10 
   4194304 |                        |     4 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1867   427352 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |    81 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   200 node`ssleay_rand_bytes+0x7a
    131072 |@@@@@@@@@@@             |   919 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@@                   |   392 node`ssl3_get_client_hello+0x56d
    524288 |@                       |   102 node`ssl3_accept+0x4a1
   1048576 |                        |    60 
   2097152 |                        |    55 
   4194304 |                        |    44 
   8388608 |                        |    11 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 4569   171822 0x1030000c8                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |   246 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |  1358 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@@@@             |  2119 node`int_thread_release+0x3a
    262144 |@@@                     |   609 node`int_thread_get_item+0x7e
    524288 |                        |   138 node`ERR_get_state+0x47
   1048576 |                        |    54 
   2097152 |                        |    34 
   4194304 |                        |    10 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 5790   130675 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |   424 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@                  |  1631 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@@           |  3167 node`int_free_ex_data+0x1d
    262144 |@                       |   480 node`BIO_free+0x69
    524288 |                        |    47 node`ssl3_digest_cached_records+0x186
   1048576 |                        |    19 
   2097152 |                        |    20 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  769   976563 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    10 node`uv_rwlock_wrlock+0x9
     65536 |@                       |    64 node`ssleay_rand_add+0xcb
    131072 |@@@@@@                  |   223 node`ssl3_accept+0x31
    262144 |@@@@@                   |   162 node`ssl3_read_bytes+0x17a
    524288 |@@@                     |    97 node`ssl3_read_internal+0xc1
   1048576 |@@                      |    85 
   2097152 |@@                      |    67 
   4194304 |@                       |    34 
   8388608 |                        |    24 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 6043   120503 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   527 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |  1986 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@@            |  3045 node`int_new_ex_data+0x1d
    262144 |@                       |   413 node`X509_STORE_CTX_init+0x2ca
    524288 |                        |    44 node`ssl3_output_cert_chain+0xcd
   1048576 |                        |    18 
   2097152 |                        |     7 
   4194304 |                        |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1547   451931 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |    88 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   162 node`ssleay_rand_bytes+0x40a
    131072 |@@@@@@@@@@@             |   725 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@@                   |   327 node`ssl3_get_client_hello+0x56d
    524288 |@                       |   103 node`ssl3_accept+0x4a1
   1048576 |                        |    40 
   2097152 |                        |    53 
   4194304 |                        |    31 
   8388608 |                        |    16 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1406   492009 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    55 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   138 node`ssleay_rand_bytes+0x40a
    131072 |@@@@@@@@@@@             |   685 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@@                   |   297 node`def_generate_session_id+0x28
    524288 |@                       |    83 node`ssl_get_new_session+0x18f
   1048576 |                        |    40 
   2097152 |@                       |    64 
   4194304 |                        |    24 
   8388608 |                        |    17 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1369   478570 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    28 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   117 node`ssleay_rand_add+0xcb
    131072 |@@@@@@@@@@@             |   631 node`ssl3_accept+0x31
    262144 |@@@@@                   |   331 node`ssl23_get_client_hello+0x660
    524288 |@                       |   108 node`ssl23_accept+0x14f
   1048576 |                        |    51 
   2097152 |                        |    57 
   4194304 |                        |    35 
   8388608 |                        |    10 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  721   849468 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    21 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |    69 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@                |   241 node`ssl3_accept+0x31
    262144 |@@@@                    |   126 node`ssl3_read_bytes+0x17a
    524288 |@@                      |    87 node`ssl3_read_internal+0xc1
   1048576 |@@                      |    64 
   2097152 |@@                      |    63 
   4194304 |@                       |    35 
   8388608 |                        |    12 
  16777216 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1375   436779 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    28 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   126 node`ssleay_rand_bytes+0x7a
    131072 |@@@@@@@@@@@@            |   722 node`ssleay_rand_pseudo_bytes+0xe
    262144 |@@@@@                   |   299 node`def_generate_session_id+0x28
    524288 |@                       |    82 node`ssl_get_new_session+0x18f
   1048576 |                        |    32 
   2097152 |                        |    45 
   4194304 |                        |    27 
   8388608 |                        |    12 
  16777216 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1410   422823 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |    28 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |   133 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@@@            |   719 node`ssl3_accept+0x31
    262144 |@@@@@                   |   308 node`ssl23_get_client_hello+0x660
    524288 |@                       |    91 node`ssl23_accept+0x14f
   1048576 |                        |    55 
   2097152 |                        |    34 
   4194304 |                        |    30 
   8388608 |                        |    11 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2073   213790 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   219 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |   645 node`def_get_class+0x4f
    131072 |@@@@@@@@@               |   800 node`int_free_ex_data+0x1d
    262144 |@@                      |   232 node`BIO_free+0x69
    524288 |                        |    83 node`ssl_free_wbio_buffer+0x2d
   1048576 |                        |    50 
   2097152 |                        |    31 
   4194304 |                        |    10 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2985   138558 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |   246 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |   968 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@             |  1450 node`int_free_ex_data+0x1d
    262144 |@                       |   238 node`BIO_free+0x69
    524288 |                        |    43 node`BIO_free_all+0x15
   1048576 |                        |    24 
   2097152 |                        |    12 
   4194304 |                        |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 2469   161517 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   236 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |   723 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@             |  1174 node`int_free_ex_data+0x1d
    262144 |@@                      |   238 node`SSL_free+0x65
    524288 |                        |    49 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
   1048576 |                        |    31 
   2097152 |                        |     9 
   4194304 |                        |     6 
   8388608 |                        |     3 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
 1578   131445 0x103000190                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |   134 node`uv_rwlock_wrlock+0x9
     65536 |@@@@@@@                 |   498 node`def_get_class+0x4f
    131072 |@@@@@@@@@@@             |   782 node`int_free_ex_data+0x1d
    262144 |@                       |   129 node`SSL_SESSION_free+0x54
    524288 |                        |    23 node`SSL_free+0xfe
   1048576 |                        |     7 
   2097152 |                        |     3 
   4194304 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  165   776700 0x103000258                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     7 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |    24 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@                 |    50 node`ssl_cert_dup+0x1cb
    262144 |@@@@@                   |    35 node`SSL_new+0xc6
    524288 |@@@                     |    23 tlsnappy.node`tlsnappy::Context::GetSSL()+0x10
   1048576 |@                       |     8 
   2097152 |                        |     5 
   4194304 |@                       |     9 
   8388608 |                        |     3 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   64  1507328 0x103001068                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     4 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |     6 node`CRYPTO_add_lock+0x64
    131072 |@@@                     |    10 node`BIO_free+0x33
    262144 |@@@@                    |    13 node`ssl3_digest_cached_records+0x186
    524288 |@@@@@                   |    14 node`ssl3_get_client_hello+0xa0d
   1048576 |                        |     2 
   2097152 |@                       |     5 
   4194304 |@                       |     5 
   8388608 |@                       |     4 
  16777216 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  141   616782 0x103000258                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@@                      |    12 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |    15 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@@                |    47 node`asn1_item_combine_free+0x1bf
    262144 |@@@@@@                  |    39 node`ASN1_item_free+0x17
    524288 |@                       |     6 node`sk_pop_free+0x2e
   1048576 |                        |     5 
   2097152 |@                       |     9 
   4194304 |@                       |     6 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   57  1233111 0x103001068                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     3 node`uv_rwlock_wrlock+0x9
     65536 |@@                      |     7 node`CRYPTO_add_lock+0x64
    131072 |@@@                     |     8 node`BIO_free+0x33
    262144 |@@@@                    |    10 node`ssl_free_wbio_buffer+0x2d
    524288 |@@                      |     6 node`ssl3_accept+0xb53
   1048576 |@@@                     |     8 
   2097152 |@@@                     |     8 
   4194304 |@@                      |     5 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
  111   544066 0x103000258                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     7 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |    16 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@                  |    31 node`X509_verify_cert+0xec
    262144 |@@@@@@@                 |    34 node`ssl3_output_cert_chain+0x103
    524288 |@@                      |    10 node`ssl3_send_server_certificate+0x48
   1048576 |                        |     3 
   2097152 |@                       |     6 
   4194304 |                        |     2 
   8388608 |                        |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   48   986453 0x103001068                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     3 node`uv_rwlock_wrlock+0x9
     65536 |@@@@                    |     9 node`CRYPTO_add_lock+0x64
    131072 |@@@                     |     6 node`BIO_free+0x33
    262144 |@@@                     |     7 node`BIO_free_all+0x15
    524288 |@@                      |     4 node`SSL_free+0x9c
   1048576 |@@@@                    |     8 
   2097152 |@@@                     |     6 
   4194304 |@@                      |     5 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   44   772282 0x103001068                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     1 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |     6 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@                 |    14 node`BIO_free+0x33
    262144 |@@                      |     5 node`BIO_free_all+0x15
    524288 |@@@@@                   |    10 node`SSL_free+0xb0
   1048576 |@                       |     2 
   2097152 |@                       |     3 
   4194304 |@                       |     2 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   26  1006985 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     1 node`uv_rwlock_wrlock+0x9
     65536 |                        |     1 node`ssleay_rand_add+0xcb
    131072 |@@@@                    |     5 node`bnrand+0xbc
    262144 |@@@@@@@@@@              |    11 node`bn_rand_range+0x13c
    524288 |                        |     1 node`BN_BLINDING_create_param+0xc2
   1048576 |                        |     1 
   2097152 |@                       |     2 
   4194304 |@@@                     |     4 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   37   563255 0x103000258                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |@                       |     2 node`uv_rwlock_wrlock+0x9
     65536 |@                       |     3 node`CRYPTO_add_lock+0x64
    131072 |@@@@@@@                 |    11 node`asn1_item_combine_free+0x1bf
    262144 |@@@@@@@@                |    13 node`ASN1_item_free+0x17
    524288 |@@                      |     4 node`ssl_cert_free+0x78
   1048576 |                        |     1 
   2097152 |@                       |     2 
   4194304 |                        |     0 
   8388608 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   10   950272 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     65536 |@@                      |     1 node`uv_rwlock_wrlock+0x9
    131072 |@@@@@@@@@@@@@@          |     6 node`ssleay_rand_bytes+0x7a
    262144 |@@                      |     1 node`bnrand+0xe0
    524288 |                        |     0 node`bn_rand_range+0x13c
   1048576 |                        |     0 node`BN_BLINDING_create_param+0xc2
   2097152 |                        |     0 
   4194304 |@@@@                    |     2 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   28   324169 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     1 node`uv_rwlock_wrlock+0x9
     65536 |@                       |     2 node`ssleay_rand_add+0x367
    131072 |@@@@@@@@@@@@@           |    16 node`bnrand+0xbc
    262144 |@@@                     |     4 node`bn_rand_range+0x13c
    524288 |                        |     1 node`BN_BLINDING_create_param+0xc2
   1048576 |@@                      |     3 
   2097152 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   20   452198 0x103000898                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@                 |     6 node`uv_rwlock_wrlock+0x9
    131072 |@@@@@@@                 |     6 node`X509_STORE_get_by_subject+0x3d
    262144 |@@@@                    |     4 node`X509_STORE_CTX_get1_issuer+0x48
    524288 |@                       |     1 node`X509_verify_cert+0x2a9
   1048576 |@@                      |     2 node`ssl3_output_cert_chain+0x103
   2097152 |                        |     0 
   4194304 |@                       |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
   28   300763 0x103000e10                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     32768 |                        |     1 node`uv_rwlock_wrlock+0x9
     65536 |@@@                     |     4 node`ssleay_rand_bytes+0x40a
    131072 |@@@@@@@@@@@@@           |    16 node`bnrand+0xe0
    262144 |@@@@                    |     5 node`bn_rand_range+0x13c
    524288 |                        |     1 node`BN_BLINDING_create_param+0xc2
   1048576 |                        |     0 
   2097152 |                        |     0 
   4194304 |                        |     1 
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    4  1769472 0x103000a28                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
    262144 |@@@@@@                  |     1 node`uv_rwlock_wrlock+0x9
    524288 |@@@@@@                  |     1 node`CRYPTO_add_lock+0x64
   1048576 |                        |     0 node`ssl_cert_free+0x36
   2097152 |@@@@@@                  |     1 node`SSL_free+0x14f
   4194304 |@@@@@@                  |     1 tlsnappy.node`tlsnappy::Socket::Close()+0x2c
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1   131072 0x103000708                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
    131072 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_rwlock_wrlock+0x9
                                            node`rsa_get_blinding+0x88
                                            node`RSA_eay_private_decrypt+0x179
                                            node`ssl3_get_client_key_exchange+0x159
                                            node`ssl3_accept+0x83f
-------------------------------------------------------------------------------
Count     nsec Lock                         Caller
    1    65536 0x103000708                  node`uv_rwlock_wrlock+0x9

      nsec ---- Time Distribution --- count Stack
     65536 |@@@@@@@@@@@@@@@@@@@@@@@@|     1 node`uv_rwlock_wrlock+0x9
                                            node`BN_MONT_CTX_set_locked+0x79
                                            node`RSA_eay_mod_exp+0x137
                                            node`RSA_eay_private_decrypt+0x22e
                                            node`ssl3_get_client_key_exchange+0x159
```

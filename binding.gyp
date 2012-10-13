{
  "variables": {
    "node_shared_openssl%": "true"
  },
  "targets": [
    {
      "target_name": "tlsnappy",
      "dependencies": [ "deps/lring/lring.gyp:lring" ],
      "include_dirs": [
        "deps/lring/include",
        "deps/lring/src"
      ],
      "sources": [
        "src/tlsnappy.cc",
        "src/bio.c"
      ],
      "conditions": [
        ["node_shared_openssl=='false'", {
          "include_dirs": [
            "<(node_root_dir)/deps/openssl/openssl/include"
          ],
          "conditions" : [
            ["target_arch=='ia32'", {
              "include_dirs": [ "<(node_root_dir)/deps/openssl/config/piii" ]
            }],
            ["target_arch=='x64'", {
              "include_dirs": [ "<(node_root_dir)/deps/openssl/config/k8" ]
            }],
            ["target_arch=='arm'", {
              "include_dirs": [ "<(node_root_dir)/deps/openssl/config/arm" ]
            }]
          ]
        }]
      ]
    }
  ]
}

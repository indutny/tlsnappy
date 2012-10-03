{
  "variables": {
    "node_shared_openssl%": "true"
  },
  "targets": [
    {
      "target_name": "tlsnappy",
      "sources": [
        "src/tlsnappy.cc",
        "src/bio.cc",
        "src/ring.cc",
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
    },
    {
      "target_name": "ring-test",
      "type": "executable",
      "include_dirs": [ "src/" ],
      "sources": [
        "src/ring.cc",
        "test/ring-test.cc"
      ]
    }
  ]
}

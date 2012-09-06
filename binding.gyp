{
  "variables": {
    "node_shared_openssl%": "true"
  },
  "targets": [
    {
      "target_name": "tlsnappy",
      "sources": [
        "src/tlsnappy.cc"
      ],
      "conditions": [
        ["node_shared_openssl=='false'", {
          "include_dirs": [
            "<(node_root_dir)/deps/openssl/openssl/include"
          ]
        }]
      ]
    }
  ]
}

{
    "targets": [
        {
            "target_name": "murmur",
            "sources": ["cpp/murmur.cc", "cpp/HashifyName.cpp"],
            "include_dirs": [
                "node_modules/napi",
                "node_modules/node-addon-api"
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
            'dependencies': [
                "<!(node -p \"require('node-addon-api').gyp\")",
            ]
        }
    ]
}

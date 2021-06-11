{
    "targets": [
        {
            "target_name": "murmur",
            "sources": ["cpp/murmur.cc", "cpp/HashifyName.cpp"],
            'include_dirs': ["<!(node -p \"require('node-addon-api').include_dir\")"],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
            'dependencies': [
                "<!(node -p \"require('node-addon-api').gyp\")",
            ]
        }
    ]
}

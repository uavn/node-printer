#!/bin/bash

# Build Linux 64bit
node-pre-gyp configure --target=$NODE_VERSION
node-pre-gyp build package --target=$NODE_VERSION --target_arch=x64

# Build Linux 32bit
node-pre-gyp configure --target=$NODE_VERSION
node-pre-gyp build package --target=$NODE_VERSION --target_arch=ia32
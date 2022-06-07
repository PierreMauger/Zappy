#!/bin/bash

make re
cd tests
mkdir -p build && cd build
conan install .. --build=gtest -s compiler.libcxx=libstdc++11
cmake ..
cmake --build . && ./bin/unit-tests

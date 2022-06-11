#!/bin/bash

make
cd tests
(mkdir build && cd build && conan install .. --build=gtest -s compiler.libcxx=libstdc++11 && cmake ..) || (cd build && cmake --build . && ./bin/unit-tests)

# Zappy

A game

## Server

### Build

```
make zappy_server
```

### Run

```
./zappy_server //ARGS
```

## AI

### Build

```
make zappy_ai
```

### Run

```
./zappy_ai //ARGS
```

## Unit-tests

### Build

```
cd tests
mkdir build && cd build
conan install .. --build=gtest -s compiler.libcxx=libstdc++11
cmake ..
cmake --build .
```

### Run

```
./bin/unit-tests
```

#!/usr/bin/env bash

mkdir build
cd build
cmake ..
cmake --build .
./bin2dec

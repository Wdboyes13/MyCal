#!/bin/bash
if [ "$1" = "--reconf" ]; then
    rm -rf ./build
fi

if [ ! -d "./build" ]; then
    mkdir ./build
    cd ./build || exit
    cmake -G Ninja ..
    cd ..
fi

cd build || exit
ninja

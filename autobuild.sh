#!/bin/bash
set -euxo pipefail

if [ "$1" = "--reconf" ]; then
    rm -rf ./build
fi

if [ ! -d "./build" ]; then
    mkdir ./build
    cd ./build || exit
    cmake -G Ninja ..
    cd ..
fi

cd ./build || exit
ninja || exit
cd .. || exit

if [ "$1" = "-i" ] || [ "$2" = "-i" ]; then
    ./install.sh
fi

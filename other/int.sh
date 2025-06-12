#!/usr/bin/env bash
set -euxo pipefail
shopt -s globstar

if [ ! -d "~/.mycal" ]; then
    mkdir ~/.mycal
fi

cd ~/.mycal/
mkdir tetris
cd tetris
git clone --depth 1 https://github.com/vicgeralds/vitetris
cd vitetris
./configure
make
make install DESTDIR="$(pwd)/.."

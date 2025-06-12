#!/usr/bin/env bash
set -euxo pipefail
shopt -s globstar

if [ ! -d "~/.mycal" ]; then
    mkdir ~/.mycal
fi

mkdir -p ~/.mycal
cd ~/.mycal
mkdir doom
cd doom # in ~/.mycal/doom
git clone --depth 1 https://github.com/chocolate-doom/chocolate-doom
cd chocolate-doom # ~/.mycal/doom/chocolate-doom
./autogen.sh
make
make install DESTDIR="$(pwd)/../launch"
cd ../launch # ~/.mycal/doom/launch
cd usr/local # ~/.mycal/doom/launch/usr/local
wget "https://github.com/freedoom/freedoom/releases/download/v0.13.0/freedoom-0.13.0.zip"
unzip freedoom-0.13.0.zip
cd freedoom-0.13.0 # ~/.mycal/doom/launch/usr/local/freedoom-0.13.0
mv *.wad ../bin
cd .. # ~/.mycal/doom/launch/usr/local/
rm freedoom-0.13.0.zip
rm -rf ../../../chocolate-doom
rm -rf freedoom-0.13.0

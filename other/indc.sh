#!/usr/bin/env bash
set -euxo pipefail
shopt -s globstar

if [ ! -d "~/.mycal" ]; then
    mkdir ~/.mycal
fi

cd ~/.mycal
mkdir dc
cd dc
wget "https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/gnudc.tar.gz"
tar xzf gnudc.tar.gz
cd gnudc
./auto.sh
make $(cat env.sh)
make install DESTDIR=$(pwd)/..
cd ..
rm -rf gnudc

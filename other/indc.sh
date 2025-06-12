#!/usr/bin/env bash
cd ~/.mycal
mkdir dc
cd dc
wget "https://github.com/Wdboyes13/MyCal/blob/main/gnudc.tar.gz"
tar xzf gnudc.tar.gz
cd gnudc
./auto.sh
make $(cat env.sh)
make install DESTDIR=$(pwd)/..
cd ..
rm -rf gnudc

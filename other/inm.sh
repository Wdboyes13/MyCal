#!/usr/bin/env bash
set -euxo pipefail
shopt -s globstar

if [ ! -d "~/.mycal" ]; then
    mkdir ~/.mycal
fi

cd ~/.mycal
mkdir mail
cd mail

git clone --depth 1 https://gitlab.com/muttmua/mutt.git
cd mutt
./prepare
./configure \
  --disable-warnings \
  --enable-gpgme \
  --enable-hcache \
  --enable-imap \
  --enable-pop \
  --enable-sidebar \
  --enable-smtp \
  --with-gss \
  --with-idn2 \
  --with-sasl \
  --with-ssl=$(brew --prefix openssl@3) \
  --with-tokyocabinet \
  --disable-debug \
  --disable-dependency-tracking \
  --prefix="$HOME/.mycal/mail" \
  --disable-nls
make
sudo make install
cd ..
rm -rf mutt


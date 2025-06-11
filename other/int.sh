cd ~/.mycal/
mkdir tetris
cd tetris
git clone --depth 1 https://github.com/vicgeralds/vitetris
cd vitetris
./configure
make
make install DESTDIR="$(pwd)/.."

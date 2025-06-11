git clone --depth 1 https://github.com/vicgeralds/vitetris
cd vitetris
./configure
make
mkdir "$HOME/.mycal/tetris"
make install DESTDIR="$HOME/.mycal/tetris/"

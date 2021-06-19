#!/bin/bash

clear
cd ./lib
gcc -Wall -fPIC -c board.c
gcc -Wall -fPIC -c piece.c
gcc -Wall -fPIC -c input.c
gcc -shared -Wl,-soname,libchess.so -o libchess.so *.o
cd ..
gcc -Wall -pedantic -Werror -Wextra -L./lib main.c -lchess
export LD_LIBRARY_PATH=.:$PWD/lib
./a.out

clear
export LD_LIBRARY_PATH=.:$PWD/lib
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./a.out
clear
cat valgrind-out.txt

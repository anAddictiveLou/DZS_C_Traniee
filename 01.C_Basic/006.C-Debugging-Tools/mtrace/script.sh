echo -e '\nOutput ex1:'
MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/006.C-Debugging-Tools/mtrace/ex1.txt
export MALLOC_TRACE
gcc -o ex1 ex1.c -g
./ex2
mtrace ./ex1 ex1.txt

echo -e '\nOutput ex2:'
MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/006.C-Debugging-Tools/mtrace/ex2.txt
export MALLOC_TRACE
gcc -o ex2 ex2.c -g
./ex2
mtrace ./ex2 ex2.txt

echo -e '\nOutput ex3:'
MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/006.C-Debugging-Tools/mtrace/ex3.txt
export MALLOC_TRACE
gcc -o ex3 ex3.c -g
./ex3
mtrace ./ex3 ex3.txt

echo -e '\nOutput ex4:'
MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/006.C-Debugging-Tools/mtrace/ex4.txt
export MALLOC_TRACE
gcc -o ex4 ex4.c -g
./ex4
mtrace ./ex4 ex4.txt

rm -rf *.txt
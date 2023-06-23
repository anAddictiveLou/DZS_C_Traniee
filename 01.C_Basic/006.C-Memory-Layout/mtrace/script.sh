MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/006.C-Memory-Layout/mtrace/a.txt
export MALLOC_TRACE

gcc ex_Mtrace.c -g
./a.out
mtrace ./a.out a.txt
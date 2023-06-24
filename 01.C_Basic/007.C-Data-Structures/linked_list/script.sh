rm a.out
MALLOC_TRACE=/home/lou/DZS-Training/01.C_Basic/007.C-Data-Structures/linked_list/a.txt
export MALLOC_TRACE

echo -e "\n**************BUILD & RUN PROGRAM****************"
gcc *.c -g
./a.out
echo -e "***************************************************\n"
echo -e "\n******************MTRACE RESULT*******************"
mtrace ./a.out ./a.txt
echo -e "****************************************************\n"
echo -e "\n*****************VALGRIND RESULT******************"
valgrind --leak-check=full ./a.out
echo -e "***************************************************\n"
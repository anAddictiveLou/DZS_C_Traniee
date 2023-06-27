echo "Build program"
make

echo -e '\nRun program with debugging'
gdb -x gdb.init

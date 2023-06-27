echo "Build program"
make
echo -e '\nSet up fo core-dump file'
ulimit -c unlimited
ulimit -a
echo -e '\nRun program'
./prog

echo -e '\nRun program with debugging'
gdb -x gdb.init prog core
ulimit -c 0
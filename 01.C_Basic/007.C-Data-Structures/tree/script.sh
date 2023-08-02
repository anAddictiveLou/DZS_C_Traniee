echo "Build program"
make
echo -e '\nSet up fo core-dump file'
ulimit -c unlimited
ulimit -a
echo -e '\nRun program'
./tree

echo -e '\nRun program with debugging'
gdb tree core
ulimit -c 0
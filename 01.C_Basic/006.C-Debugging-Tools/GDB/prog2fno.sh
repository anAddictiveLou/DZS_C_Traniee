echo "Build program"
make turn_off_stack_protect

echo "Run debugging"
gdb -x gdb.init prog2fno
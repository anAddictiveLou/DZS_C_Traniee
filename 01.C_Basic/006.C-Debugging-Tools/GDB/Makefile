all:
	gcc -g -o prog prog.c
	gcc -fstack-protector -g -o prog2 prog2.c
turn_off_stack_protect:
	gcc -fno-stack-protector -g -o prog2fno prog2.c
clean:
	rm -rf ex1 ex2 ex3
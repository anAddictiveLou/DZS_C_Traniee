buildgdb:
	gcc -ggdb3 -o ex1 ex1.c
	gcc -ggdb3 -o ex2 ex2.c
	gcc -ggdb3 -o ex3 ex3.c
	gcc -fstack-protector -ggdb3 -o stack_smashing_detected stack_smashing_detected.c
buildnormal:
	gcc -o ex1 ex1.c
	gcc -o ex2 ex2.c
	gcc -o ex3 ex3.c
clean:
	rm -rf ex1 ex2 ex3
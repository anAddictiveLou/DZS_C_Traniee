.PHONY: all stage1 stage2 stage3 stage4
all: 
	gcc -o ./obj/main.out ./src/*.c -I .
stage1: 
	gcc -E ./src/lib.c -o ./stage/lib.i -I .
	gcc -E ./src/main.c -o ./stage/main.i -I .
stage2:
	gcc -S ./src/lib.c -o ./stage/lib.s -I .
	gcc -S ./src/main.c -o ./stage/main.s -I .
stage3:
	gcc -c ./src/lib.c -o ./stage/lib.o -I .
	gcc -c ./src/main.c -o ./stage/main.o -I .
stage4: 
	gcc -o ./obj/main.out ./stage/*.o -I .
clean:
	rm -rf ./obj/*.out ./stage/*

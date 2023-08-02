all:
	g++ -Wall -Werror -g -o tree main.cc tree.cc queue.cc
test:
	valgrind --leak-check=full --show-leak-kinds=all ./tree
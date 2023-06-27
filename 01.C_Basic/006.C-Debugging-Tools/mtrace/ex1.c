#include <stdlib.h>
#include <mcheck.h>
#define SIZE 10

int main(void) {

	mtrace(); /* Starts the recording of memory allocations and releases */

	int* a = NULL;

	a = malloc(SIZE * sizeof(int)); /* allocate memory and assign it to the pointer */
	if (a == NULL) {
		return 1; /* error */
	}
    for (int i = 0; i < SIZE + 5; i++)
    {
        a[i] = i;
    }
	free(a); /* we free the memory we allocated so we don't have leaks */
	muntrace();

	return 0; /* exit */

}
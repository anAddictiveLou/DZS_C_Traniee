#include <stdio.h>
static int counter = 10;
void myFunction() {
    static int counter = 0; // Static local variable
    
    counter++;
    printf("Counter: %d, address: %p\n", counter, &counter);
}

int main() {
    myFunction(); // Call 1
    myFunction(); // Call 2
    myFunction(); // Call 3
    
    return 0;
}

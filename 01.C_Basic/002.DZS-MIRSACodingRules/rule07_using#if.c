#include<stdio.h>
#define MIN -5
#if MIN < 0
#define MAX 5
#define PRINT {do {printf("Hello wolrd\n");} \
              while(0);}
#else 
#error "It's not a natural number!!!!"
#endif
int main()
{
  PRINT
  return 0 ;
} 
 
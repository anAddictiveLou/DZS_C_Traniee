#include <stdio.h>
#include <pthread.h>
#include <errno.h>

void *thread_start(void *args)
{
	pthread_exit(NULL);
}

int main (void)
{
	pthread_t threadID;
	int ret;
	long count = 0;

	while(1)
	{
		if(ret = pthread_create(&threadID, NULL, thread_start, NULL))
		{
			printf("pthread_create() fail ret: %d\n", ret);
			perror("Fail reason:");
			break;
		}
		count++;
	}
	printf("Number of threads are created:%ld\n", count);
	return 0;
}
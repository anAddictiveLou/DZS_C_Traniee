#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include "queue.h"

#define THRESHOLD     5

pthread_t tid;

/*Counter la bien toan cuc duoc 2 thread su dung*/

int counter;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   //khai báo mutex
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;      // khai bao bien dieu kien

void* threadFunc(void)
{
   pthread_mutex_lock(&mutex);  /*Khoa mutex de bao ve bien counter*/
   printf("pthread has started\n");

   while(counter < THRESHOLD)
   {
       counter += 1;
       sleep(5);
   }

   pthread_cond_signal(&cond);
   printf("pthread has finished, counter = %d\n", counter);
   pthread_mutex_unlock(&mutex);  /*Nha khoa mutex*/

   pthread_exit(NULL);
}

int main(void)
{
   int ret = 0;

   ret = pthread_create(&tid, NULL, (void*)&(threadFunc), NULL);
   if (ret != 0)
   {
       printf("pthread created fail\n");
   }

   while(counter < THRESHOLD)  /*Kiem tra gia tri cua counter co dung nhu mong doi khong*/
   {
       pthread_cond_wait(&cond, &mutex);   /*Cho signal tu thread khac*/
       printf("Global variable counter = %d.\n", counter);  /*Truy cap bien counter*/
   }

   pthread_join(tid, NULL);

   return 0;
}
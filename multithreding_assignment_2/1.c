/*1.Write a pthread application where main task terminated but pending pthreads task still
execute.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
pthread_t thread_id,thread_id2;
void *myThreadFun(void *vargp)
{
	printf("Printing from Thread 1\n");
	return NULL;
}
void *myThreadFun2(void *vargp)
{
	printf("Printing from Thread 2 \n");
	return NULL;
}
int main()
{
	int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    int ret2 = pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
    if (ret==0)
    {printf("All the thread are executing\n");}
    pthread_exit(NULL);
    printf("All the thread are not executing ");
    return(0);
}
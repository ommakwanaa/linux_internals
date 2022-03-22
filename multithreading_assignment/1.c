//1.Write a multithreading program, where threads runs same shared golbal variable of the process between them.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
int global_varriable = 100;
pthread_t thread_id,thread_id2;
void *myThreadFun(void *vargp)
{
	printf("Printing from Thread 1\n");
    int shared = global_varriable*global_varriable;
    printf("multiplying global varriable and the ans is: %d\n",shared);
	return NULL;
}
void *myThreadFun2(void *vargp)
{
	printf("Printing from Thread 2 \n");
    int shared = global_varriable+global_varriable;
    printf("addition global varriable and the ans is: %d\n",shared);
	return NULL;
}
int main()
{
	int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    int ret2 = pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    return(0);
}

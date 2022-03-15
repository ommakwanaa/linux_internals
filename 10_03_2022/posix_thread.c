#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

pthread_t thread_id,thread_id2;
void *myThreadFun(void *vargp)
{
	// sleep(1);
	printf("Printing from Thread 1\n");
	return NULL;
}
void *myThreadFun2(void *vargp)
{
	// sleep(1);
	printf("Printing from Thread 2 \n");
	return NULL;
}
int main()
{
	int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    int ret2 = pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
    if (ret)
    {
        printf("Thread is not created\n");
    }
    else{
        printf("Thread is created\n");
        // getchar();
        // pthread_join(thread_id, NULL);
    }
    if (ret2)
    {
        printf("Thread is not created\n");
    }
    else{
        printf("Thread is created\n");
        getchar();
        // sleep(2);
        // pthread_join(thread_id2, NULL);
    }
    return(0);
}

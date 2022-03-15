#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include<string.h>
#include <pthread.h>
pthread_t thread_id,thread_id2;
static void* myThreadFun(void *arg){
    pthread_detach(pthread_self());
    printf("\ninside a thread");
    return 0;
}
int main()
{
    int s = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    // pthread_join(thread_id, NULL);
    if (s)
    {
        printf("thread is not createdd");
    }
    else{
        printf("thread is created");
        pthread_exit(NULL);
    }
    
    // return(0);
}

//4. Write a program where pthread task displays the thread id and also prints the calling
//process pid./*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include<fcntl.h>
pthread_t thread;
void *thread_new(void *threadid){
    printf("\nnewly created thread is executing\n");
    int t = pthread_cancel(thread);
    if(t==0){ //returns 0 after successful
        printf("cancle thread with id %lu\n",thread);  }
    return NULL;}
int main(){
    printf("Creating thread\n");
    int rc = pthread_create(&thread,NULL,thread_new,NULL);
    int ret = pthread_self(); // a line add kri che me khali
    printf("calling process process ID = %u\n", ret); // a line add kri che me khali
    if (rc){printf("Creating thread failed\n");}
    else
    {   printf("Thread id: %lu",thread);
        pthread_join(thread, NULL);
    }
    return 0;

}
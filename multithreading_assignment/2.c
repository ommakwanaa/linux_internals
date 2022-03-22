//2.Write a program where thread cancel itself.(use pthread_cancel())

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
    if (rc){printf("Creating thread failed\n");}
    else
    {   printf("Thread id: %lu",thread);
        pthread_join(thread, NULL);
    }
    return 0;

}
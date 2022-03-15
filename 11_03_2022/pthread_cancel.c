#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include<fcntl.h>
void *printhello(void *threadid){
    printf("\nbuddy ");
    while(1);
}
int main(){
    pthread_t thread;
    int rc , t = 0;
    printf("creating thread\n");
    rc = pthread_create(&thread,NULL,printhello,NULL);
    printf("\n thread id: %lu",thread);
    sleep(6);
    t = pthread_cancel(thread);
    if (t==0)
    {
        printf("thread canceled");
        printf("\n thread id: %lu",thread);

    }
    

}
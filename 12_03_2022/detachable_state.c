#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREAD 3
int i =0;
void *myfun(void *null){
    i++;
    int result =0;
    result = result +i*1000;
    printf("result = %d\n",result);
    pthread_exit(NULL);
}
int main(int argc,char *argv[]){
    pthread_t thread[NUM_THREAD];
    pthread_attr_t attr;
    int RC , t, STATUS,detache_state;
    pthread_attr_init (&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    for ( t = 0; t< NUM_THREAD; t++)
    {
       printf("creating thread %d\n",t);
       pthread_create(&thread[t],&attr,myfun,NULL);
    }
    pthread_attr_getdetachstate(&attr, &detache_state);
    printf("\nDetach state: %d\n", (int *)detache_state);



    printf("\nexiting from main thread\n");
    pthread_exit(NULL);




    return 0;
}
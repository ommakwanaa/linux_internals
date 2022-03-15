#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include<string.h>
#include <pthread.h>
pthread_t thread_id,thread_id2;
static void* myThreadFun(void *arg){
    char *s = (char *) arg;
    printf("%s",s);
    sleep(5);
    return(char*)s;
    return 0;
}
int main()
{
    char *res;
    int s = pthread_create(&thread_id, NULL, myThreadFun, "hello world");
	// int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    printf("message from main()\n");
    sleep(3);
    pthread_join(thread_id, &res);
    printf("\nthread returned %s\n",res);
    // return(0);
}

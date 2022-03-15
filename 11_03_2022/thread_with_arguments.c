#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
pthread_t thread_id,thread_id2;
static void* myThreadFun(void *arg){
    char *s = (char *) arg;
    printf("%s",s);
    return 0;
}
int main()
{
    void *res;
    int s = pthread_create(&thread_id, NULL, myThreadFun, "NULL");
	// int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    printf("message from main()\n");
    // sleep(3);
    pthread_join(thread_id, NULL);
    // return(0);
}

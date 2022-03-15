#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
pthread_t thread_id,thread_id2;
void *myThreadFun(void *vargp)
{
    long tid;
    int pid;
    tid = (long)thread_id;
    pid = getpid();
    printf("Hello There! thread %ld, pthread ID - %lu,  pid - %d\n", tid, pthread_self(),pid);
    pthread_exit(NULL);
	return NULL;
}
int main()
{
	int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    if (ret)
    {
        printf("Thread is not created\n");
    }
    else{
        printf("Thread is created\n");
        // getchar();
        pthread_join(thread_id, NULL);
    }
    return(0);
}

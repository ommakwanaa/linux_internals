#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

void *foo(void *arg)
{
    char *str = (char *)arg;
    printf("thread task called by=%s\n", str);

    pthread_mutex_lock(&lock);
    if (done == 1)
    {
        printf("Waiting on condition variable cond1\n");
        pthread_cond_wait(&cond1, &lock);
    }
    else
    {
        printf("signaling condition\n");
        pthread_cond_signal(&cond1);
    }
    pthread_mutex_unlock(&lock);
    printf("Returning thread\n");

    return NULL;
}
int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, foo, "THD one");
    sleep(1);
    done = 2;
    pthread_create(&tid2, NULL, foo, "THD two");

    pthread_join(tid2, NULL);
    printf("completed");

    return 0;
}
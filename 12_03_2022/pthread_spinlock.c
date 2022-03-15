#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <bits/types.h>
#include <sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
    int rc, count = 0;
    printf("entered %d getting spin lock\n", (int *)i);
    rc = pthread_spin_lock(&slock);
    printf("%d thread unlock the spin lock", (int *)i);
    rc = pthread_spin_unlock(&slock);
    printf("%d thread complete", (int *)i);
    return NULL;
}
int main()
{
    int rc = 0;
    pthread_t thread, thread1;

    if (pthread_spin_init(&slock, PTHREAD_PROCESS_PRIVATE) != 0)
    {
        perror("init");
    }

    printf("main get spin lock\n");
    rc = pthread_spin_lock(&slock);

    printf("main, create the spin lock thread\n");

    rc = pthread_create(&thread, NULL, spinlockthread, (int *)1);

    printf("main, wait a bit holding the spin lock\n");
    sleep(5);

    printf("\nmain, now unlock the spin lock");
    rc = pthread_spin_unlock(&slock);

    if (rc == 0)
    {
        printf("\nmain thread seccuessfully unlocked\n");
    }
    else
    {
        printf("\nmain thread unseccuessfully unlocked\n");
    }

    printf("\nmain, wait for the thread to end\n");
    rc = pthread_join(thread, NULL);
    printf("\nmain completed\n");

    return 0;
}
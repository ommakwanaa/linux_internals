#include <stdio.h>

#include <pthread.h>

#include <stdlib.h>

#include <string.h>

#include <sys/mman.h>

void *
Proc(void *param)
{

    sleep(2);

    return 0;
}

int main()
{

    pthread_attr_t
        Attr;

    pthread_t
        Id;

    void *stk;

    size_t
        siz;

    int
        err;

    size_t
        my_stksize =
            0x30000000;

    void *
        my_stack;

    pthread_attr_init(&Attr);

    pthread_attr_getstacksize(&Attr, &siz);

    pthread_attr_getstackaddr(&Attr, &stk);

    printf("Default: Addr=%08x default size=%d\n", stk, siz);

    my_stack = (void *)malloc(my_stksize);

    // printf("Default: Addr=%08x default size=%d\n",stk,siz);

    pthread_attr_setstack(&Attr, my_stack,
                          my_stksize);

    pthread_create(&Id, &Attr,
                   Proc,
                   NULL);

    pthread_attr_getstack(&Attr, &stk,
                          &siz);

    printf("Newly defined stack : Addr=%08x and size=%d\n", stk, siz);

    sleep(3);

    return (0);
}

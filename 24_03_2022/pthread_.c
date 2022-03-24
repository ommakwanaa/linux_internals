#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id, thread_id1, thread_id3;
void *myThreadFun(void *vargp)
{
    // sleep(1);
    printf("Printing from Thread 1\n");
    return NULL;
}
static void *myThreadFun1(void *arg)
{
    char *s = (char *)arg;
    printf("Printing from Thread 2\n");
    printf("%s", s);
    return 0;
}

struct my_Struct
{
    int s;
};
void *threadstruct(void *arg)
{
    struct my_Struct *obj1;
    obj1 = (struct my_Struct *)arg;
    printf("Printing from Thread 2\n");
    printf("structure message: %ld\n", obj1->s);
    return NULL;
}
int main()
{
    struct my_Struct obj1;
    obj1.s = 10;
    int ret = pthread_create(&thread_id, NULL, myThreadFun, NULL);
    int ret2 = pthread_create(&thread_id1, NULL, myThreadFun1, "passing NULL\n");
    int ret3 = pthread_create(&thread_id3, NULL, threadstruct, (void*)&obj1);

    if (ret)
    {
        printf("Thread is not created\n");
    }
    else
    {
        printf("Thread is created\n");
        // getchar();
        pthread_join(thread_id, NULL);
        pthread_join(thread_id1, NULL);
    }
    return (0);
}

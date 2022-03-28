/*2.Write a program where a structure of information passed to pthread task function, and
display structure of information.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
pthread_t thread_id;
struct multi{
    int s_value;
};

void *myThreadFun(void *arg){
    struct multi *value;
    value = (struct multi *) arg;// typecasting a structure
	printf("Printing from Thread 1\n");
    printf("value of struct is %d\n",value->s_value);
	return NULL;
}

int main()
{
    struct multi value1;
    value1.s_value=1000;
	int ret = pthread_create(&thread_id, NULL, myThreadFun, (void *)&value1);
    if (ret==0)
    {
        printf("Thread executing\n");
    }
    
    pthread_join(thread_id,NULL);
    return(0);
}


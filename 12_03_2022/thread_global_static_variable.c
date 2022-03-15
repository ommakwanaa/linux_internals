#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedvar = 5;
void *thread_inc(void * arg){
    sharedvar++;
    printf("after increment = %d",sharedvar);
}
void *thread_dec(void * arg){
    sharedvar--;
    printf("after decrement = %d",sharedvar);
}
int main(){
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,thread_inc,NULL);
    pthread_create(&thread2,NULL,thread_dec,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf(" shared var = %d",sharedvar);
    return(0);

}
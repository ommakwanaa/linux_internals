#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int sharedvar = 5;
pthread_mutex_t my_sem;
void *thread_inc(void * arg){
    pthread_mutex_lock(&my_sem);
    sharedvar++;
    printf("after increment = %d",sharedvar);
    pthread_mutex_unlock(&my_sem);
}
void *thread_dec(void * arg){
    pthread_mutex_lock(&my_sem);
    sharedvar--;
    printf("after decrement = %d",sharedvar);
    pthread_mutex_unlock(&my_sem);

}
int main(){
    pthread_t thread1,thread2;
    pthread_mutex_init(&my_sem,NULL);
    pthread_create(&thread2,NULL,thread_dec,NULL);
    pthread_create(&thread1,NULL,thread_inc,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL); 
    
    printf(" shared var = %d",sharedvar);
    return(0);

}
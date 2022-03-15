#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include<fcntl.h>

pthread_t thread_id1,thread_id2;
int fd;
void *myThreadFun(void *p)
{
    char *str ,buff[1000];
    int pid,n;
    str = (char *)p;
    pid = getpid();
    printf("%s: \t start now: \t for process: %d \n\n",str,pid);
    do
    {
        n = read(fd,buff,1000);
        printf("%s: \t read: \t %d \n\n" ,str,pid);
        printf("\n.......................\n");
        write(1,buff,n);
        printf("\n.......................\n");
        sleep(3);

    } while (n);
    printf("%s: \t finished now: \t for process: %d \n\n",str,pid);
    
}
int main()
{
    fd = open("08_03_2022.txt",O_RDONLY);
    printf("the file is opened");
    pthread_create(&thread_id1,NULL,myThreadFun,"thread one");
    pthread_create(&thread_id2,NULL,myThreadFun,"thread two");
    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
}

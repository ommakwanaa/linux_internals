#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>

int main()
{

    pid_t pid;
    pid  = fork();
    if(pid == 0){
        sleep(5);
        printf("i am child with delay and my child pid is %d \n",getpid());
    }
    else{
        int pid2;
        printf("i am parent pro pid = %d",getpid());
        pid2 = wait(0);
        printf("child %d executed normally\n",pid2);
        printf("parent process pro pid  = %d",getpid());
    }
    return(0);
}
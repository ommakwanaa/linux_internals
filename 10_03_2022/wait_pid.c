#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>

int main(){
    int pid;
    int status;
    printf("parent : %d\n",getpid());
    pid = fork();
    if (pid == 0)
    {
        printf("child: %d\n",getpid());
        sleep(2);
    }
    printf("parent reporting to child whose pid =%d\n",waitpid(pid,&status,0));
}
//ommakwana07
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

int main(){
    int pid1;
    printf("my process pid is %d\n",getpid());
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("this process is child process\n");
        execl("/bin/ls","ls ","-lh",NULL);
        
    }
    else{
        wait(0);
        printf("this process is parent process\n");

    }

    return 0;

        
}
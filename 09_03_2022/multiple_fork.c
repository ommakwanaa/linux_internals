//ommakwana07
#include<stdio.h>
#include<unistd.h>

int main(){
    int pid1;
    printf("my process pid is %d\n",getpid());
    pid1 = fork();
    if (pid1==0)
    {
        sleep(2);
        printf("new child process pid is %d\n",getpid());
        printf("new parent process ppid is %d\n",getppid());
        fork();
    }
    else{
        printf("my process pid is %d\n",getpid());
        printf("my process ppid is %d\n",getppid());

    }
    while(1){

    }
    return 0;

        
}
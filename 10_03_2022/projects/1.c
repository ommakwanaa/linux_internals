//ommakwana07
#include<stdio.h>
#include<unistd.h>

int main(){
    int pid1;
    printf("my process pid is %d\n",getpid());
    pid1 = fork();
    if (pid1 != 0)
    {
        printf("this process is parent process\n");
        printf("this parent process pid is %d\n",getpid());
        printf("child parent's parent process pid is %d\n",getppid());
        fork();   
        fork();
    }
    else{
        printf("this process is child process\n");
        printf("this child process pid is %d\n",getpid());
        printf("child parent's parent process pid is %d\n",getppid());

    }
    while(1){

    }
    return 0;

        
}
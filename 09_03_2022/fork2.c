//ommakwana07
#include<stdio.h>
#include<unistd.h>

int main(){
    int pid1;
    printf("my process pid is %d\n",getpid());
    pid1 = fork();
    if (pid1 > 0)
    {
        sleep(2);
        printf("new child process pid is %d\n",getpid());
        printf("new parent process ppid is %d\n",getppid());
    }
    else{
        printf("my process pid is %d\n",getpid());
        printf("my process ppid is %d\n",getppid());

    }
    // if(pid1){ //pid!=0
    // // run this as a parent process
    // {
    // printf("this is a parent process\n");
    // }
    // } else{
    // // run this as s child process
    // {
    // printf("this is a child process\n");
    // }
    // }
    while(1){

    }
    return 0;

        
}
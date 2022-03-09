#include<stdio.h>
#include<unistd.h>

int main(){
    printf("my process pid is %d\n",getpid());
    fork();
    printf("my process ppid is %d\n",getppid());
    fork();
    printf("linux kernal\n");

        
}
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main(){
    pid_t pid;
    int sig_no;
    printf("enter the pid of the process need to be sent :\n");
    scanf("%d",&pid);
    printf("enter the signal that need to be sent:");
    scanf("%d",&sig_no);
    kill(pid,sig_no);
    
}
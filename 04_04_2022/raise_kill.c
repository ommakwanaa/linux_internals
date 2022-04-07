#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void sig_handler(int signum){
    printf("inside handeler function\n");
}
int  main()
{
    pid_t pid;
    signal(SIGUSR1,sig_handler);
    printf("insider main function\n");
    pid =  getpid();
    kill(pid,SIGUSR1);
    printf("inside main function\n");
    return 0;
}
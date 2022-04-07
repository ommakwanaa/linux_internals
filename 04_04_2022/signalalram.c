#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void sighand(int signum){
    printf("i have to wake up my boss now\n");
    //alram(5);
}
int  main()
{
    signal(SIGALRM,sighand);
    alarm(3);
    while (1);
        return 0;
}
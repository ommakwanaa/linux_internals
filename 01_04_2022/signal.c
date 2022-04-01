#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sighand(int signum){

    printf("intruct signal rec'd... but no termination on control c\n");
    signal(SIGINT,SIG_DFL);

}
void main(){
    signal(SIGINT,sighand);
    for (int i = 0;; i++)
    {
        printf("i = %d\n",i);
        sleep(1);
    }
    return 0;
    
}
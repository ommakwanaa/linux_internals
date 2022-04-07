#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void signal_handler(int signa){
    if (signa == SIGINT)
    {
        printf("caught sigint!\n");
    }
    else if (signa == SIGALRM)
    {
        printf("caught SIGALRM!\n");
    }
    else
    {
        printf("caught sigabrt!\n");
        fprintf(stderr, "unexpected signal!\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
int main(){
    if (signal(SIGINT,signal_handler)==SIG_ERR)
    {
        fprintf(stderr,"cannot ignore sigup!\n");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGALRM,signal_handler)==SIG_ERR)
    {
        fprintf(stderr,"cannot ignore sigalrm!\n");
        exit(EXIT_FAILURE);
    }
    alarm(4);
    if (signal(SIGABRT,signal_handler)==SIG_ERR)
    {
        fprintf(stderr,"cannot ignore sigabrt!\n");
        exit(EXIT_FAILURE);
    }
    // abort();
    for (;;)
    {
        pause();
    }
    
    
    return 0;
    
}
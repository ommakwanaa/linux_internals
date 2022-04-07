// used to kill the signal

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void printsignalset(sigset_t *set)
{
    const int siglist[] = {SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV};
    const int *signames[] = {"SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV"};
    const int siglen = 8;
    for (int i = 0; i < siglen; i++)
    {
        int ret = sigismember(set, siglist[i]);
        if (ret == -1)
        {
            perror("sigismember: ");
            exit(EXIT_FAILURE);
        }
        else if (ret == 1)
        {
            printf("signal %s %d is in the set \n", signames[i], siglist[i]);
        }
        else
        {
            printf("signal %s %d is not in the set \n", signames[i], siglist[i]);
        }
    }
}

int main(void)
{
    sigset_t set;
    if (sigprocmask(0, NULL, &set) != 0)
    {
        perror("sigprocmask: ");
        exit(EXIT_FAILURE);
    }
    printf("...initial signal mask for this process : ----\n");
    printsignalset(&set);
    //#if1
    if (sigaddset(&set, SIGINT) != 0)
    {
        perror("sigaddset: ");
        exit(EXIT_FAILURE);
    }

    if (sigprocmask(SIG_SETMASK, &set, NULL) != 0)
    {
        perror("sigprocmask: ");
        exit(EXIT_FAILURE);
    }
    printf("...new signal mask for this process : ----\n");
    printsignalset(&set);
    //#endif1
    int secToSleep = 20;
    printf("ctrl+c. Try killing this program with 'kill -kill %d'. Going to sleep form %d seconds.\n", getpid(), secToSleep);
    sleep(secToSleep);
    printf("sleep returned\n");

    printf("removing all signals from mask\n");
    sigfillset(&set);
    sigprocmask(SIG_SETMASK,&set,NULL);
    printsignalset(&set);
    sleep(1);
    printf("exited normally\n");
    return 0;
}
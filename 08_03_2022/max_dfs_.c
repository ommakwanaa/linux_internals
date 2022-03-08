#include<unistd.h>
#include<stdio.h>

int main(){
    printf("max number of fds are: %d\n", getdtablesize());

    return 0;
}
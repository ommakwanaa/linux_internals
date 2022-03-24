#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char buff_comm[20];
    strcpy(buff_comm,"gedit test.txt");
    printf("system library function use fork to create child process\n");
    printf("child process execute exec  which loads and run new program provided by the system arguments\n");
    int x = system(buff_comm);
    printf("return from system  %d\n",x);
    return(0);
}

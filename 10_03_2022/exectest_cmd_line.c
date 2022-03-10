#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    int i;
    printf("\n file name: %s \n",argv[0]);
    printf("\n total number of file: %d \n",argc);
    execl(argv[1], argv[2], 0);
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("args are %s",argv[i]);
    //     printf("\n");
    // }
    printf("\n");
    
        
}
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void){
    printf("client process writing");
    char clientmsg[]= " linux system kernal programing";
    int fd = open("cli_ser_fifo",O_WRONLY);
    if (fd==-1)
    {
        perror("can not open fifo");
        return EXIT_FAILURE;
    }
    write (fd,clientmsg,strlen(clientmsg));
    close(fd);
    return 0;

    

}
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
    printf("server -- listening");
    int code = mkfifo("cli_ser_fifo",0764);
    if(code==-1){perror("error occured");}
    int fd = open("cli_ser_fifo",O_RDONLY);
    if(fd == -1){
        perror("error occured");  // this will return error to standard eroor devices 
        return 0;
    }
    printf("fifo open");
    char serverrr[100];
    memset(serverrr,0,100);
    int res;
    char len;
    while (1)
    {
        
        res = read(fd,&len,1);
        if(res == 0){
            break;
        }
        read(fd, serverrr, len);
        printf("server recieved %s\n", serverrr);

    printf("server received %s \n",serverrr);      

    }


    printf("eof line");
    close(fd);
    printf("flie closed");
    return 0;  
}
//ommakwana07
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
    int pid1=1;
    int fd1 , ret;
    char buffer[30];

    printf("My process pid is %d\n",getpid());
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("This process is child process\n");
        fd1 = open("linux.txt", O_RDONLY); // to read the file
        printf("Printing from buffer\n");
        while (ret = read(fd1, buffer, 30)>0)
        {
           printf("\n%s", buffer); 
        } // reading the file
    }
    else{
        
        wait(0);
        printf("\nThis process is parent process\n");
    }
    return 0;

        
}
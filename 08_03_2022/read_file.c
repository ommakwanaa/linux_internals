#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(){
    int fd2,retval;
    char buffer;
    fd2 = open("read.txt",O_RDONLY); // to read the file 
    printf("the file linux_append discriptor for open is  %d\n",fd2); // printing discriptor
    if (fd2>0) //checking file exist or not
    {
        while ((retval = read(fd2, &buffer, 1)) > 0) // reading the file
            printf("%c", buffer);    //printing the file
        if (retval < 0) {
            perror("\nRead failure");
        }
    }

    int close(int fd2); // closing the file 

}
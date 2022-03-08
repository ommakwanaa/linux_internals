//ommakwana07

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>

int main(){
    int fd2,retval,len;
    char buffer[]= "HI I'M OM AND AM WRITING IN THE FILE";
    int nbyte =strlen(buffer);
    fd2 = open("write.txt",O_CREAT|O_RDWR,777); // to read the file 
    printf("the file linux_append discriptor for open is  %d\n",fd2); // printing discriptor
    if (fd2>0) //checking file exist or not
    {
        if ((len = write(fd2, buffer, nbyte)) < 0) {
            perror("Problem in writing to file");
            exit(1);
        }
    }
    lseek(fd2, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_END);
    lseek(fd2, 0, SEEK_CUR);
    read(fd2, buffer, nbyte);
    printf("read buffer value is: %s\n", buffer);


    int close(int fd2); // closing the file 

}
#include<stdio.h>
#include<fcntl.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = creat("linux_append.txt",777); // to creat the file 

    fd2 = open("linux_append.txt",O_APPEND | O_RDONLY); // to read the file 

    printf("the file linux_append discriptor for creat is  %d\n",fd1); // printing discriptor
    printf("the file linux_append discriptor for open is  %d\n",fd2); // printing discriptor


    int close(int fd1); // closing the file 
    int close(int fd2); // closing the file 

}
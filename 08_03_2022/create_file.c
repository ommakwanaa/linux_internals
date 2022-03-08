#include<stdio.h>
#include<fcntl.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = creat("linux1.txt",777);
    fd2 = creat("linux3.txt",777);
    fd3 = creat("linux2.txt",777);

    printf("the file 1 discriptor is  %d\n",fd1);
    printf("the file 2 discriptor is  %d\n",fd2);
    printf("the file 3 discriptor is  %d\n",fd3);

    int close(int fd1);
    int close(int fd2);
    int close(int fd3);
}
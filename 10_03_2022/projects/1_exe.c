#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    //executable file named 2 is needed to run this program
    int fd;
    fd = open("/home/om/om/linux_internals/10_03_2022/projects/1",O_RDONLY,777);
    printf("%d\n",fd);
    return 0;
}

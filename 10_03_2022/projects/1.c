#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd;
    fd = execl("/home/om/om/linux_internals/10_03_2022/projects/3","" ,0);//dont forget to typr file name inpaths
    if(fd == -1)
        printf("error opening file");
    return 0;
}

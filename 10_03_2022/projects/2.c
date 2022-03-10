#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd;
    fd = open("/home/om/om/linux_internals/10_03_2022/projects/2nd", O_RDONLY, 777);
    printf("file descriptor of a open system call is %d\n", fd);
    return 0;
}
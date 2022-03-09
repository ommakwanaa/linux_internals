//ommamkwana07

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(){
int fd1,fd2,fd3,fd4;
fd1 = open("linux.txt",O_WRONLY | O_CREAT | O_TRUNC,0777);
fd2 = open("linux1.txt",O_WRONLY | O_CREAT | O_TRUNC,0777);
printf("fd1 is = %d\n",fd1);
printf("fd2 is = %d\n",fd2);
fd3 = dup(fd1);
printf("fd3 is = %d\n",fd3);
close(fd3);
close(fd2);
close(fd1);

}
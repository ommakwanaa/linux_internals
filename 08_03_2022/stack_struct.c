#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
    struct stat st;
    int fd;
    stat("lseek.c",&st);
    printf("file size is %ld",(st.st_size));
}
//ommakwana07
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
    struct stat st;
    int fd;
    stat("1.c",&st);
    printf("File inode = %lu\n",(st.st_ino));
    printf("File size of blocks = %lu\n",(st.st_blksize));
    printf("File size is %ld",(st.st_size));
}
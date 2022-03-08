//ommakwana07


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
    int fd;
    int result;

    fd = open("om.txt", O_WRONLY | O_CREAT | O_EXCL, 0600);
    result = lseek(fd, 3996, SEEK_SET);

    /* write just one byte at the end */
    result = write(fd, "", 1);

    /* do other things here */
    
    close(fd);
    return 0;
}
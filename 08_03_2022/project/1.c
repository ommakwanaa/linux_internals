//ommakwana07

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd1, fd2, retval;
    char buffer[30];
    fd2 = open("copy.txt",O_CREAT | O_RDWR | O_APPEND, 777);
    fd1 = open("read.txt", O_RDONLY); // to read the file
    while ((read(fd1, buffer, 30)) > 0)
    {
    } // reading the file
    int i;
    if (fd1 > 0)
    {
        if ((i = write(fd2, buffer, 30)) < 0)
        {
            perror("error occured while writing to a file");
        }
    }

    int close(int fd1); // closing the file
    int close(int fd2); // closing the file
}

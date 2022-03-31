#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

    char s[20];
    int fd;

    mkfifo("newfifo", 0644); // newfifo is a pipe i.e. a file named pipe create fifo(named pipe)
    // int om = 10;
    printf("Before OPEN()...\n");
    fd = open("newfifo", O_RDONLY); // OPEN fifo for write only
    printf("after open()...\n");

    read(fd, s, sizeof(s));
    printf("data %s", s);
    return 0;
}

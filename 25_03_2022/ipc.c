#include<unistd.h>
#include<stdio.h>

int main(){
    int fds[2], res,i;
    char *buff1 = "aaaaaaaaaaaaaaaaaaaa";
    char *buf = "12345678912345678912";
    char buf2[40];
    res = pipe(fds);
    if (res == -1)
    {
        perror("pipe");
        // exit(1);
    }
    
    write(fds[1],buff1,20);
    write(fds[1],buf,20);
    read(fds[0],buf2,40);
    for (int i = 0; i < 40; i++)
    {
        printf("%c",buf2[i]);
    }
    printf("\n\n");
    
}
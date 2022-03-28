#include <unistd.h>
#include <stdio.h>
int fds[2];
void parent_code()
{
    char buf1[20] = "i am makwana om ";
    char buf2[20] = "my friend are with me";
    close(fds[0]);
    write(fds[1], buf1, 20);
    write(fds[1], buf2, 20);
    printf("end of parent\n");
}
void child_code()
{
    char buf2[40];
    int i, n;
    close(fds[1]);
    n = read(fds[0], buf2, 40);
    printf("no of char is = %d\n", n);
    for (int i = 0; i < 40; i++)
    {
        printf("%c", buf2[i]);
    }
    printf("\nend of child\n");
}
int main()
{
    int res, i;
    pid_t p;
    res = pipe(fds);
    if (res == -1)
    {
        perror("pipe");
        // exit(1);
    }
    p = fork();
    if (p == 0)
    {
        printf("\nchild\n");
        child_code();
    }
    else
    {
        printf("\nparent\n");
        parent_code();
    }
    printf("\n\n");
}
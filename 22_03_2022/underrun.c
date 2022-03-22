//for lower boundry violation

#include <stdio.h>
#include <stdlib.h>
void buggy()
{
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int) * 5);
    printf("malloc checking addr=%08x and size = %d\n", intptr, sizeof(int) * 5);
    for (int i = 0; i < 3; i++)
    {
        *intptr = 100;
        printf("value at the ptr int ptr = %ld\n", (*intptr));
        intptr--;
    }
}
int main()
{
    buggy();
    return 0;
}

//export  EF_PROTECT_BELOW=1
//gcc underrun.c -o under -lefence
//./a.out
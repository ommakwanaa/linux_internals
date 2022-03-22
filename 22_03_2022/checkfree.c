#include<stdio.h>
#include<stdlib.h>
void buggy(){
    int *ptrint;
    ptrint = (int *)malloc(sizeof(int));
    * ptrint = 100;
    printf("value at ptr intr = %d",(*ptrint));
    free(ptrint);
    
    *ptrint = 99;

}
int main()
{
    buggy();
    return 0;
}
#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]){
    int i;
    printf("\nthis is file name  %s",argv[0]);
    printf("\ntotal args  %d",argc);
    printf("\nargs passed");
    for (int i = 0; i < argc; i++)
    {
        printf("\n %d %s",i,argv[i]);
    }
    printf("\n");
    
}
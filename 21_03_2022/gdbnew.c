#include<stdio.h>
#include<string.h>
int main(){
    char *src;
    src = malloc(1<<31);
    fgets(src,500,stdin);
    printf("%s\n",src);
    }
#include<stdio.h>
#include<string.h>
int main(){
    char *src;
    src = malloc(100);
    fgets(src,500,stdin);
    printf("%s\n",src);
    }
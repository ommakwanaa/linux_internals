#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //referncing
    int *i;
    float *j;
    char *a;
    int k = 5;
    i = &k;
    float h = 2.30;
    j = &h;
    char y = 'S';
    a = &y;

    printf("referencing value of i %d\n",i);
    printf("referencing value of j %d\n",j);
    printf("referencing value of k %d\n",a);
    i = NULL;
    j = NULL;
    a = NULL;
    printf("de referencing value of i %d\n",i);
    printf("de referencing value of j %d\n",j);
    printf("de referencing value of k %d\n",a);

}

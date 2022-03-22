#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //referncing
    int val =5;
    int *ptr ;
    ptr = &val;
    printf("\t%d\t%d\t%d\t%d",val,*ptr,ptr,&val);
    //de referencing
    int dref;
    dref = *ptr;
}
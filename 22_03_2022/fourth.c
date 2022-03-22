#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int roll;
    char name[40],gender;
    float height;  

};
int main(){
    struct student first;
    printf("\n size od struct student %3d\n",sizeof(first));

}
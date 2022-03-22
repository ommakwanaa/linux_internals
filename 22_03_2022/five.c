#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int roll;
    char name[40],gender __attribute__((aligned(2))); // it is used to allign the gender 3 bit to save the memmory from wasting 
    //it is an atribute which provide minimum alignement for my structure variable
    float height;

}__attribute__((packed));
int main(){
    struct student first;
    printf("\n size od struct student %3d\n",sizeof(first));

}
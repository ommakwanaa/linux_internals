#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int roll;
    char name[40],gender;
    float height;

}first;
int main(){
    struct student second;
    struct student third = {102,"baburao",'m',7.0};
    printf("\n roll\t\t\t\t\t name \t\t gender \theight \n");
    first.roll = 101;
    strcpy(first.name,"om makwana p");
    first.gender='m';
    first.height=5.6;
    printf("\n %3d\t%40s\t%c\t%1.2f",first.roll,first.name,first.gender,first.height);
    printf("\n %3d\t%40s\t%c\t%1.2f",third.roll,third.name,third.gender,third.height);
}
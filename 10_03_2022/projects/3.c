#include<stdio.h>
#include<unistd.h>

int main(){
    printf("i am going to execute a programe\n");
    int ret;

    ret = execl("/usr/bin/vim","vim","linux.txt",0);
    if(ret == -1){
        printf("this is not supported\n");
    } 
}
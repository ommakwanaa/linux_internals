#include<stdio.h>
#include<unistd.h>

int main(){
    printf("i am going to execute a ls programe\n");
    int ret;

    ret = execl("/usr/bin/gedit","gedit","linux.txt",0);
    if(ret == -1){
        printf("this is not supported\n");
    } 
}
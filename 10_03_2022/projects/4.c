#include<stdio.h>
#include<unistd.h>

int main(int argc ,char *argv[]){
    printf("i am going to execute a ls programe\n");
    int ret;

    ret = execl("/home/om/om/linux_internals/10_03_2022/projects/commandline","abc","def",argv[1],argv[2],NULL);
    if(ret == -1){
        printf("this is not supported\n");
    } 
}
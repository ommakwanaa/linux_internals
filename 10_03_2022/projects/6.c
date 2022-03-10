#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

void callback1(void){
    printf("\ncallback 1");
}
void callback2(void){
    printf("\ncallback 2");
}
void callback3(void){
    printf("\ncallback 3");
}
int main(){
    printf("\nregistar callback 1\n");
    atexit(callback1);
    printf("\nregistar callback 2\n");
    atexit(callback2);    
    printf("\nregistar callback 3\n");
    atexit(callback3);

}

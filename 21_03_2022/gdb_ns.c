#include<stdio.h>
#include<string.h>
void printmsg(char *msg){
    if (msg!=NULL){
        printf("%s\n",msg);
    }
}
int main(){
    char buff[] = "linux";
    printmsg(NULL);
    return 0;
}

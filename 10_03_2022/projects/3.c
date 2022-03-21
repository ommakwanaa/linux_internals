#include <stdio.h>
#include <unistd.h>
int main(){
    int ret = execl("/usr/bin/pstree", "pstree", 0, 0);
    if (ret == -1)    {
        printf("execl returned error %d\n", ret);
    }
    return 0;
} 

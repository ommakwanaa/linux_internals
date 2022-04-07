/*1.write a program that creates a shared memory region and displays shared memory id
and also print address at which shared area in this process starts from.*/

#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#define shm_size 0x1000
int main(){
    key_t key;
    int *address;
    int shmget_id  = shmget(key, shm_size, IPC_CREAT|0660);
    if (shmget_id ==-1)
    {
        printf("\ncant create shared memmory location\n");
    }
    else{
        printf("\nshared memmory id is %d\n",shmget_id );
    }

    address = shmat(shmget_id, 0, 0);
    printf("\nshared memmory address is %p\n",address);

}


#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256

// void toggleCase(char *buf, int cnt);

// union semun {
// int val;
// struct semid_ds *buf;
// unsigned short *array;
// struct seminfo *__buf;
// };
// union semun sem_union;

int main()
{
    int semId, shmId;
    char *pShm;
    struct sembuf smop;

    semId = semget(MY_KEY, 1, 0660);
    if (semId < 0)
    {
        printf("could not create semaphore\n");
        return (1);
    }
    else
    {
        printf("opened a semaphore ID is %d\n", semId);
    }
    // semctl(semId,0,SETVAL,0);
    shmId = shmget(MY_KEY, SHM_SIZE, 0660);
    if (shmId < 0)
    {
        printf("could not create shared segment \n");
        return (2);
    }

    pShm = shmat(shmId, NULL, 0);
    if (!pShm)
    {
        printf("could not attach shared memory segment.\n");
        return (3);
    }
    while (1)
    {
        /* code */
        printf("Client: Enter some request message to send to server\n");
        fgets(pShm, MSG_LEN, stdin);
        smop.sem_num = 0;
        smop.sem_op = 1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);
        smop.sem_num = 1;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);
        puts(pShm + RESP_MSG_START);
    }
}
void toggleCase(char *buf, int cnt)
{
    int ii;
    for (ii = 0; ii < cnt; ii++)
    {
        if ((buf[ii] >= 'A') && (buf[ii] <= 'Z'))
            buf[ii] += 0x20;
        else if ((buf[ii] >= 'a') && (buf[ii] <= 'z'))
            buf[ii] -= 0x20;
    }
}
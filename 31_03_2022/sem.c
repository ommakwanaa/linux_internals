#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/io.h>
#include <stdlib.h>
#include <unistd.h>
struct sembuf sem_op;
union semnum sem_union;

int sid;
union semnum
{
    int val;
    struct sid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};
int get_release(void)
{
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;

    if (semop(sid, &sem_op, 1) < 0)
    {
        printf("failed\n");
        return -1;
    }
}

int get_semaforce(void)
{
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(sid, &sem_op, 1) < 0)
    {
        printf("failed");
        return -1;
    }
}

int main()
{
    int i;
    sleep(2);
    sid = semget((key_t)10, 1, 0666 | IPC_CREAT);
    printf("\n semaforce id : %d\n", sid);

    sem_union.val = 1;
    if (semctl(sid, 0, SETVAL, sem_union) < 0)
    {
        printf("error\n");
    }
    for (int i = 0; i < 5; i++)
    {
        get_semaforce();
        printf("\n%d got the semaphore \n", getpid());
        sleep(1);
        printf("\n%d release the semaphore \n", getpid());
        get_release();
        sleep(1);
    }
    if (semctl(sid, 0, IPC_RMID, sem_union) < 0)
    {
        printf("\nfails to delete the semaforce\n");
    }
    else
    {
        printf("\nsemaforce deleted\n");
    }
}

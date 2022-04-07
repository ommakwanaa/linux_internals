/*2.write a program that uses msgctl() and prints number of messages,number of bytes in
message queue and also get Maximum number of bytes in queue for already existing
message queue and also remove message queue at the end.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <string.h>
typedef struct
{
    long msgtype;
    char buffer[100];
} msg;

int main()
{
    msg m1, m2;

    m1.msgtype = 10;
    for (int i = 0; i < 100; i++)
    {
        m1.buffer[i] = 'a';
    }

    int message_queue_id;
    struct msqid_ds buf;

    message_queue_id = msgget(32, IPC_CREAT | 0664);
    msgsnd(message_queue_id, &m1, sizeof(msg), 0);
    msgsnd(message_queue_id, &m2, sizeof(msg), 0);
    printf("Message queue id is = %d\n", message_queue_id);
    msgctl(message_queue_id, IPC_STAT, &buf);

    printf("Here are the details of the queue\n");
    printf("Number of msg's in queue = %hi\n", buf.msg_qnum);
    printf("NUmber of bytes in message queue = %u\n", buf.msg_cbytes);
    printf("Max no of bytes in queue = %hi\n", buf.msg_qbytes); // msg_qbytes

    printf("Removing queue with id %d\n", message_queue_id);
    int remove_id = msgctl(message_queue_id, IPC_RMID, NULL);
    printf("Queue removed");

    return 0;
}
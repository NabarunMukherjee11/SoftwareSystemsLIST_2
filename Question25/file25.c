#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
int main(){
    key_t key;
    int msgid;
    struct msqid_ds queue_info;
    key = ftok(".", 'A');
    msgid = msgget(key, IPC_CREAT | 0666);

    int a=msgctl(msgid, IPC_STAT, &queue_info);

    printf("Access Permission: %o\n", queue_info.msg_perm.mode);
    printf("UID: %d\n", queue_info.msg_perm.uid);
    printf("GID: %d\n", queue_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s\n", ctime(&queue_info.msg_stime));
    printf("Time of Last Message Received: %s\n", ctime(&queue_info.msg_rtime));
    printf("Time of Last Change: %s\n", ctime(&queue_info.msg_ctime));
    printf("Size of the Queue: %ld bytes\n", (long)queue_info.msg_cbytes);
    printf("Number of Messages in the Queue: %ld\n", (long)queue_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %ld bytes\n", (long)queue_info.msg_qbytes);
    printf("PID of msgsnd: %d\n", queue_info.msg_lspid);
    printf("PID of msgrcv: %d\n", queue_info.msg_lrpid);

    return 0;
}

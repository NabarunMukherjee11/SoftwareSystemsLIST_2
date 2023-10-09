#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
int main(){
	struct msqid_ds queue_info;
	key_t key;
	int msgid;
	key=ftok(".",'E');
	msgid=msgget(key, IPC_CREAT|  0700);
	int a=msgctl(msgid, IPC_STAT, &queue_info);
	printf("The current permission is %o\n", queue_info.msg_perm.mode);
	
	mode_t newmode= 0777;
	queue_info.msg_perm.mode= newmode;
	int status= msgctl(msgid, IPC_SET, &queue_info);;
	printf("The new permission is %o\n", queue_info.msg_perm.mode);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>

struct msg_buffer{
	long int msg_type;
	char msg_text[80];
};

int main(){
	key_t key;
	int msgid;
	key = ftok(".",'H');
	msgid= msgget(key, IPC_CREAT | IPC_EXCL | 0777);
	
	struct msg_buffer msq;
	printf("Enter the message type\n");
	scanf("%ld", &msq.msg_type);
	printf("Enter the message\n");
	getchar();
	fgets(msq.msg_text, sizeof(msq.msg_text), stdin);
	size_t size=strlen(msq.msg_text);

	int a= msgsnd(msgid, &msq, size+1, 0);
	return 0;
}


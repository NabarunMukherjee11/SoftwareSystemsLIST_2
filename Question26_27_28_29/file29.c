#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
int main(){
	key_t key;
        int msgid;
        key=ftok(".",'E');
	msgid= msgget(key, 0);
	int a = msgctl(msgid, IPC_RMID, NULL);
	printf("Removed\n");
	return 0;
}

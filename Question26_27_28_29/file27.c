/*
============================================================================
Name : file27.c
Author : Nabarun Mukherjee
Description : Write a program to receive messages from the message queue.
 a. with 0 as a flag
 b. with IPC_NOWAIT as a flag

Date: 13th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct message_buffer{
	long int msg_type;
	char message[80];
};

int main(){
	key_t key;
	int msgid;
	key=ftok(".",'H');
	msgid=msgget(key, IPC_CREAT | IPC_EXCL | 0777);
	
	struct message_buffer msg_queue1; //for blocking
	struct message_buffer msg_queue2; //for non blocking
	printf("Enter the message type for 0 as a flag:\n");
	scanf("%ld", &msg_queue1.msg_type);
	printf("Enter the message tupe for IPC_NOWAIT as a flag\n");
	scanf("%ld", &msg_queue2.msg_type);
	int ret1= msgrcv(key, &msg_queue1, sizeof(msg_queue1.message), msg_queue1.msg_type, 0);
	int ret2= msgrcv(key, &msg_queue2, sizeof(msg_queue2.message), msg_queue2.msg_type, IPC_NOWAIT);
	printf("From blocking, The Message Type %ld\n The Message %s\n ", msg_queue1.msg_type,  msg_queue1.message);
	printf("From No blocking, The Message Type %ld\n The Message %s\n", msg_queue2.msg_type,  msg_queue2.message);
	return 0;
}


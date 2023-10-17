/*
============================================================================
Name : file24.c
Author : Nabarun Mukherjee
Description : Write a program to create a message queue and print the key and message queue id.
Date: 13th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(){
	key_t key;
	key=ftok(".", 'a');
	int msgid=msgget(key, IPC_CREAT | 0666);
	printf("key = %d\n", (int)key);
	printf("Message Queue ID = %d\n", msgid);
	return 0;
}

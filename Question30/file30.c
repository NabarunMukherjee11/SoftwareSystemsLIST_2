/*
============================================================================
Name : file30a.c
Author : Nabarun Mukherjee
Description : Write a program to create a shared memory.
 a. write some data to the shared memory
Date: 16th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
	key_t key;
	int shmid;
	char *data;
	key = ftok(".",'b');

	shmid= shmget(key, 1024, IPC_CREAT | 0744);
	data = shmat(shmid, 0, 0); //0 for the same address in the directorty & 0 for the the r/w privledges
	printf("Enter the text\n");
	scanf("%[^\n]", data);
	return 0;
}


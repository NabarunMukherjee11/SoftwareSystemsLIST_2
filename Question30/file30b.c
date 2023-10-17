/*
============================================================================
Name : file30b.c
Author : Nabarun Mukherjee
Description : Write a program to create a shared memory.
 b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 13th Oct, 2023.
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
	key = ftok(".", 'b');

	shmid = shmget(key, 1024, 0);
	char* data;
	data = shmat(shmid, 0, SHM_RDONLY);
	printf("Text from shared memory: %s\n", data);
	return 0;
}

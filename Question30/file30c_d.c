/*
============================================================================
Name : file30c_d.c
Author : Nabarun Mukherjee
Description : Write a program to create a shared memory.
 c. detach the shared memory
 d. remove the shared memory

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
	key=ftok(".",'b');

	shmid = shmget(key, 1024, 0);
	int a= shmdt(NULL);
	printf("Shared Memory is detached");
	int b= shmctl(shmid, IPC_RMID, NULL);
	printf("Shared Memory is deleted");
	return 0;
}

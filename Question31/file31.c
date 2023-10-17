/*
============================================================================
Name : file31.c
Author : Nabarun Mukherjee
Description : Write a program to create a semaphore and initialize value to the semaphore.
	 	a. create a binary semaphore
 		b. create a counting semaphore

Date: 14 Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main(){
	union semun {
    		int val; // Value of the semaphore
	};
	union semun semSet1, semSet2;
	key_t key1, key2;
	int binarySemaphore, countingSemaphore;
	key1=ftok(".",'A');
	key2=ftok(".",'B');
	binarySemaphore = semget(key1, 1, IPC_CREAT | 0744);
	countingSemaphore = semget(key2, 1, IPC_CREAT | 0744);
	
	semSet1.val = 1; //binary semaphore
	semSet2.val = 10; //counting semaphore

	int semctlStatus1 = semctl(binarySemaphore, 0, SETVAL, semSet1);
	int semctlStatus2 = semctl(countingSemaphore, 0, SETVAL, semSet2);
	printf("Semaphores are created\n");
	printf("Binary Semaphore: %d \nCounting Semaphore: %d \n", binarySemaphore, countingSemaphore);
	return 0;
}


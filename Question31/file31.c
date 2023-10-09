#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main(){
	key_t key1, key2;
	int binarySemaphore, countingSemaphore;
	key1=ftok(".",'A');
	key2=ftok(".",'B');
	binarySemaphore = semget(key1, 1, IPC_CREAT | 0744);
	countingSemaphore = semget(key2, 1, IPC_CREAT | 0744);

	printf("Semaphores are created\n");
	printf("Binary Semaphore: %d \n Counting Semaphore: %d \n", binarySemaphore, countingSemaphore);
	return 0;
}


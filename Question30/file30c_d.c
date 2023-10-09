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

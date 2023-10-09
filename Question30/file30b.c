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

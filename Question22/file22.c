#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
int main(){
	fd_set read_fds;
	struct timeval timeout;
	timeout.tv_sec=10;
        timeout.tv_usec=0;
	int fifo_fd=open("fifofile", O_RDONLY| O_NONBLOCK);
	if(fifo_fd==-1){
		printf("Fifo file descriptor couldnt be made\n");
                return 0;
	}

	FD_ZERO(&read_fds);
	FD_SET(fifo_fd, &read_fds);
	printf("Waiting for data in FIFO\n");

	int s=select(fifo_fd+1, &read_fds, NULL, NULL, &timeout);
	if(s==-1){
		printf("select system call not working\n");
		return 0;
	}
	else if(s==0){
		printf("The waiting time is over\n");
		return 0;
	}
	return 0;
} 

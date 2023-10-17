/*
============================================================================
Name : file20read.c
Author : Nabarun Mukherjee
Description : Write two programs so that both can communicate by FIFO -Use one way communication 
Date: 11 Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd=open("myfifo", O_RDONLY);
	char buff[30];
	read(fd, buff, sizeof(buff));
	printf("The text from the file: %s\n", buff);
	return 0;
}	

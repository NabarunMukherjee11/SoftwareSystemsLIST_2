/*
============================================================================
Name : file20write.c
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
	int fd=open("myfifo", O_WRONLY);
	char buff[30];
	printf("Enter the test to be sent to FIFO File: ");
	scanf("%[^\n]", buff);
	write(fd, buff, sizeof(buff));
	return 0;
}

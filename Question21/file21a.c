/*
============================================================================
Name : file21a.c
Author : Nabarun Mukherjee
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 12 Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd1=open("myfifo1", O_WRONLY);
	int fd2=open("myfifo2", O_RDONLY);
	char buff1[30], buff2[30];
	printf("Enter the text");
	scanf("%[^\n]", buff1);
	write(fd1, buff1, sizeof(buff1));
	read(fd2, buff2, sizeof(buff2));
	printf("The text from FIFO file: %s\n", buff2);
	return 0;
}



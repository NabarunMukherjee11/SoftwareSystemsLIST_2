/*
============================================================================
Name : file16.c
Author : Nabarun Mukherjee
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication

Date: 9 Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int fd1[2], fd2[2];
	char buff1[50];
	char buff2[50];
	int a=pipe(fd1);
	int b=pipe(fd2);
	if(a==-1 || b==-1){
		printf("Error creating pipes\n");
		exit(0);
	}
	if(!fork()){
		close(fd1[0]); //closes read end of fd1 for child
		close(fd2[1]); //closes write end of d2 for child
		printf("Enter message to parent: ");
		scanf("%[^\n]", buff1);
		write(fd1[1], buff1, sizeof(buff1));
		read(fd2[0], buff2, sizeof(buff2));
		printf("Message from parent: %s\n", buff2);
	}
	else{
		close(fd1[1]); //Close write end of fd1 for parent
		close(fd2[0]); //Close read end of fd2 for parent
		//child wrote into fd1 first, we can read from fd1 
		read(fd1[0], buff1, sizeof(buff1));
		printf("Message from child: %s\n", buff1);
		printf("Enter message to child: ");
		scanf(" %[^\n]", buff2);
		write(fd2[1], buff2, sizeof(buff2));
	}
	return 0;
}

/*
============================================================================
Name : file15.c
Author : Nabarun Mukherjee
Description : Write a simple program to send some data from parent to the child process
Date: 8 Oct, 2023.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
int main(){
	char buff[50];
	int fd[2];
	int a=pipe(fd);
	if(a==-1){
		printf("Error in creating pipe\n");
		exit(0);
	}
	if(fork()){
		close(fd[0]); //closes read file descriptor
		printf("We are inside the parent process\n");
		printf("Enter the message to be sent to child: \n");
		scanf("%[^\n]", buff); //Reads till newline
		write(fd[1], buff, sizeof(buff));
	}
	else{
		close(fd[1]); //closes write file descriptor
		read(fd[0], buff, sizeof(buff));
		printf("The message from parent is: %s\n", buff);
	}
	wait(0); //Wait till children have been terminated
}


/*
============================================================================
Name : file18.c
Author : Nabarun Mukherjee
Description : Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.

Date: 10 Oct, 2023.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd1[2], fd2[2];
	int a=pipe(fd1);
	int b=pipe(fd2);
	if(a==-1 || b==-1){
		printf("Error in creating PIPES\n");
		exit(0);
	}
	if(!fork()){
		dup2(fd1[1],1);
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[2]);
		execlp("ls","ls", "-l", (char*) NULL);
	}
	else{
		if(!fork()){
			dup2(fd1[0],0);
			dup2(fd2[1],1);
			close(fd1[1]);
			close(fd2[0]);
			execlp("grep", "grep", "^d", (char*) NULL);
		}
		else{
			dup2(fd2[0],0);
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[1]);
			execlp("wc", "wc", (char*) NULL);
		}
	}
}



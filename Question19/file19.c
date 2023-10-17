/*
============================================================================
Name : file19.c
Author : Nabarun Mukherjee
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 11 Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
	const char *fifoname1="FIFOfrom_mkfifo";
	const char *fifoname2="FIFOfrom_mknod";
	if(mkfifo(fifoname1, 0666) == -1){
		printf("Error at creating FIFO file using mkfifo");
	}
	if(mknod(fifoname2, S_IFIFO | 0666, 0) == -1){
		printf("Error at creating FIFO file using mknod");
	}
	return 0;
}

/*
============================================================================
Name : file14.c
Author : Nabarun Mukherjee
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Date: 8 Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int array[2]; //File Descriptor of pipe will be stored in this array
	int a = pipe(array);
	if(a == -1){ // To check if the pipe is made
		printf("Run the file again\n");
		exit(0);
	}
	char data[]="Cristiano Ronaldo is the greatest player in the world";
	int wr_bytes=write(array[1], data, sizeof(data));
     	if(wr_bytes==-1){
		printf("Write not working\n");
		exit(0);
	}
	char get[40];
	int rd_bytes=read(array[0], get, wr_bytes);	
	if(rd_bytes==-1){
		printf("Read not working\n");
		exit(0);
	}
	printf("%s\n",get);
	return 0;
}


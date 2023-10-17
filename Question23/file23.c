/*
============================================================================
Name : file23.c
Author : Nabarun Mukherjee
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 13 Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
        long OPEN_MAX;
        int fd[2];
        OPEN_MAX = sysconf(_SC_OPEN_MAX); // maximum number of file descriptors which can be open in a process
        printf("The maximum number of files opened in a process: %ld\n", OPEN_MAX);
        printf("The size of a pipe: %d\n", _PC_PIPE_BUF);
        return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main(){
	int fd[2];
	int a= pipe(fd);
	if(a==-1){
		printf("Error creating a pipe\n");
		exit(0);
	}
	if(!fork()){
		close(1); // file descriptor with value 1 is closed STDOUT
		close(fd[0]); // the read end of the pipe is closed
		dup(fd[1]); //	dup will assign the file descriptor value 1(lowest) to the fd[1] 
		execlp("ls", "ls", "-l", (char*) NULL); //the execlp will output ls -l in the file descriptor with value 1
	}
	else{
		close(0); // file decriptors with value 0 is closed ie STDIN
		close(fd[1]); // the write end of the pipe is closed
		dup(fd[0]); // dup will assign the file descriptor value 0(lowest) to the fg[0]
		execlp("wc", "wc", (char*) NULL); //the execlp will take input from pipe(fd value 0)  and execute 
	}
}



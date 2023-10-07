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

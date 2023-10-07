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

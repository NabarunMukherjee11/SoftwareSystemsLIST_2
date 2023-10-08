#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd2=open("myfifo1", O_RDONLY);
        int fd1=open("myfifo2", O_WRONLY);
        char buff1[30], buff2[30];;
        printf("Enter the text");
        scanf("%[^\n]", buff1);
        write(fd1, buff1, sizeof(buff1));
	read(fd2, buff2, sizeof(buff2));
        printf("The text from FIFO file: %s\n", buff2);
        return 0;
}

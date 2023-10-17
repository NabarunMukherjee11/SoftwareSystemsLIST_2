/*
============================================================================
Name : file34bclient.c
Author : Nabarun Mukherjee
Description : Write a program to create a concurrent server.
                 b. use pthread_create
Date: 17th Oct, 2023.
============================================================================
*/
#include <sys/types.h>  // Import for `socket`, `connect`
#include <sys/socket.h> // Import for `socket`, `connect`
#include <netinet/ip.h> // Import for `struct sockaddr_in`, `htons`
#include <stdio.h>      // Import for `perror` & `printf`
#include <unistd.h>     // Import for `_exit`, `read`, write`

void main()
{
    int socketFileDescriptor;
    int connectStatus;        

    struct sockaddr_in address; 

    ssize_t readBytes, writeBytes; 
    char dataFromServer[100];

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        perror("Error while connecting to server!");
        _exit(0);
    }
    printf("Client to serrver connection successfully established!\n");
    readBytes = read(socketFileDescriptor, dataFromServer, 100);
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from server: %s\n", dataFromServer);

    writeBytes = write(socketFileDescriptor, "I'm the client!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to server!");

    getchar();
    close(socketFileDescriptor);
}

/**
 * @file mainClient.c
 * @author Vincenzo Susso
 */

// -- Libraries --
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "serverClient.h"
#include "utilities.h"

// -- Procedures & Functions Prototypes --


int main(void) {
	// Used to manage the client
	int data_socket;

	//Used to manage the communication with the server
	struct sockaddr_in server;

	// Used to Send/Receive message
    char string[MAX_LENGTH_STRING] = NULL_STRING;


	initSocket();

    // Making end-point
    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(data_socket == SOCKET_ERROR) {
        printf("Error with the function socket()\n");
        pause();
        exit(EXIT_FAILURE);
    }

    // Defining Server
    server = getServer();
    server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    // Start communication with the server
    if(connect(data_socket, (struct sockaddr *)&server, sizeof server) == SOCKET_ERROR) {
        printf("Error with the function connect()\n");
        printErrorWindows();
        endCommunication(&data_socket);
        pause();
        exit(EXIT_FAILURE);
    }

    // Starting message
    receiveMessage(&data_socket, string, sizeof(string));
    printf("%s\n", string);

    resetString(string);

    printf("\nInsert two strings separated by a space: ");
    scanf("%[^\n]s", string);

    sendMessage(&data_socket, string, sizeof(string));

    resetString(string);

    receiveMessage(&data_socket, string, sizeof(string));
    printf("\n%s\n", string);

    endCommunication(&data_socket);

    pause();

    exit(EXIT_SUCCESS);
}

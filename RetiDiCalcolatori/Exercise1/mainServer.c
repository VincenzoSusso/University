/**
 * @file mainServer.c
 * @author Vincenzo Susso
 */

// -- Libraries --
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "serverClient.h"
#include "utilities.h"

// -- Constant --
#define START_MESSAGE "Connessione avvenuta\0"

int main(void) {
	//Used to manage the server
	int connection_socket;
	struct sockaddr_in server;

	// Used to manage the connection with the client
	int data_socket;
	int client_length;
	struct sockaddr_in client;

	// Used to Send/Receive message
	char string[MAX_LENGTH_STRING] = NULL_STRING;


	initSocket();

    // Making end-point
    connection_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(connection_socket == SOCKET_ERROR) {
        printf("Error with the function socket()\n");
        pause();
        exit(EXIT_FAILURE);
    }

    // Defining Server
    server = getServer();

    // Binding the server information to the end-point
    if(bind(connection_socket, (struct sockaddr *)&server, sizeof server) == SOCKET_ERROR) {
    	printf("Error with the function bind()\n");
    	printErrorWindows();
    	endCommunication(&connection_socket);
    	pause();
    	exit(EXIT_FAILURE);
    }

    // Setting the server to listen
    if(listen(connection_socket, QUEUE_SIZE) == SOCKET_ERROR) {
    	printf("Error with the function listen()");
    	printErrorWindows();
    	endCommunication(&connection_socket);
    	pause();
    	exit(EXIT_FAILURE);
    }

    printf("The server is working!\n\n");
    while(true) {
    	client_length = sizeof(client);
    	data_socket = accept(connection_socket, (struct sockaddr *) &client, &client_length);

    	if(data_socket == SOCKET_ERROR) {
    		printf("Error with the function accept()\n");
        	printErrorWindows();
        	endCommunication(&connection_socket);
        	pause();
        	exit(EXIT_FAILURE);
    	}

    	printf("Connection with: %s\n", inet_ntoa(client.sin_addr));

    	// Sending start message
    	strcpy(string, START_MESSAGE);
    	sendMessage(&data_socket, string, sizeof(string));

    	resetString(string);

    	// Receiving string to split and modify
    	receiveMessage(&data_socket, string, sizeof(string));
    	addNullCharacterString(string);

    	char *token = strtok(string, " "); // Used to split the string
    	char response[MAX_LENGTH_STRING] = NULL_STRING;
    	char temp[MAX_LENGTH_STRING]; // Used to not modify the token

		strcpy(temp, token);
		uppercaseString(temp); //First token uppercase
		strcat(temp, " ");
    	strcat(response, temp);

    	token = strtok(NULL, " ");
    	while(token != NULL) {
    		strcpy(temp, token);
    		lowercaseString(temp); //Second token lowercase --> if the string has more than one space the following words will be lowercase
    		strcat(temp, " ");
    		strcat(response, temp);
    		token = strtok(NULL, " ");
    	}

    	addNullCharacterString(response);
    	strcpy(string, response);

    	sendMessage(&data_socket, string, sizeof(string)); // Sending the strings
    }

    pause();

    exit(EXIT_SUCCESS);
}

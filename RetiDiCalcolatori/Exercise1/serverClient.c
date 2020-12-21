/**
 * @file serverClient.c
 * @author Vincenzo Susso
 */

// -- Libraries --
#include "serverClient.h"

// -- Procedures & Functions Prototypes --
struct sockaddr_in getServer(void) {
	struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SERVER_PORT);

	return server;
}

void initSocket(void) {
	#if defined WIN32
		WSADATA wsaData;
		if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
			printf("Error with the WSAStartup()");
			printErrorWindows();
		}
	#endif
}

void sendMessage(int *socket, const void *message, const size_t message_length) {
	size_t total = 0;
	ssize_t number_bytes = 0; // It could be -1

	while(total != message_length) {
		number_bytes = send(*socket, (message + total), (message_length - total), 0);

		if(number_bytes == SOCKET_ERROR) {
			printf("Error with the function send()\n");
	    	printErrorWindows();
	    	endCommunication(socket);
	    	pause();
	    	exit(EXIT_FAILURE);
		}

		total += number_bytes;
	}
}

void receiveMessage(int *socket, void *buffer, const size_t buffer_length) {
	ssize_t number_bytes = 0; // It could be -1

	do {
		number_bytes = recv(*socket, buffer, buffer_length, 0);

		if(number_bytes == SOCKET_ERROR) {
			printf("Error with the function recv()\n");
			printErrorWindows();
			endCommunication(socket);
			pause();
			exit(EXIT_FAILURE);
		}

	} while(number_bytes == 0); // No bytes read
}

void printErrorWindows(void) {
	#if defined WIN32
		printf("Error %d\n", WSAGetLastError());
	#endif
}

void endCommunication(const int* socket) {
	#if defined WIN32
		WSACleanup();
		closesocket(*socket);
	#else
		close(socket);
	#endif
}

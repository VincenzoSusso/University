/**
 * @file serverClient.h
 * @author Vincenzo Susso
 */

// -- Libraries --
#ifndef serverClient_h
	#define serverClient_h

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

#ifdef WIN32
    #include <winsock.h>
#else
	#define closesocket close
    #include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <unistd.h>
#endif

// -- Constant --
#define SERVER_PORT 10000
#define QUEUE_SIZE 5

// -- Procedures & Functions Prototypes --
struct sockaddr_in getServer(void);
void initSocket(void);
void sendMessage(int *socket,const void *message,const size_t message_length);
void receiveMessage(int *socket, void *buffer, const size_t buffer_length);
void printErrorWindows(void);
void endCommunication(const int* socket);

#endif

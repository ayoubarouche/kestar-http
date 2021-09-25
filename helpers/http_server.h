#ifndef __HTTP_SERVER_CONFIGURATION__
#define __HTTP_SERVER_CONFIGURATION__
#ifndef __LIBRARIES_INCLUDED__
#define __LIBRARIES_INCLUDED__
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#endif



//the server socket
#ifndef __SERVER_SOCKET__
#define __SERVER_SOCKET__
int server_fd;
#endif

//define the socket address of the http server
// it will contains the address (IP , PORT) of the server
#ifndef __SERVER_ADDRESS__
#define __SERVER_ADDRESS__
struct sockaddr_in address;
#endif

//the address struct size
// we need the size to help us to bind the address of the http server
#ifndef __ADDRESS_SIZE__
#define __ADDRESS_SIZE__
int addrlen = sizeof(address);
#endif

//the port of the http server
#ifndef __SERVER_PORT__
#define __SERVER_PORT__
const int PORT = 8080;
#endif
// define the number of clients to connect to our http server
#ifndef __NUMBER_OF_CLIENT_TO_CONNECT__
#define __NUMBER_OF_CLIENT_TO_CONNECT__
#define NUMBER_OF_CLIENT 10
#endif

// it's a table of addressess of the client
#ifndef __CLIENT_ADDRESSES__
#define __CLIENT_ADDRESSES__
// the addresses of the clients conected to the server
struct sockaddr client_addresses[NUMBER_OF_CLIENT];
// it will be incremented any time a client connected (help us to handle the number of client already connected)
int client_addresses_tour = 0;
#endif
//the buffer size of received messages from the http client
#ifndef __RECEIVED_MESSAGE_BUFFER_SIZE__
#define __RECEIVED_MESSAGE_BUFFER_SIZE__
#define BUFFER_SIZE 30000

#endif
#ifndef __SOME_HTML_NEEDED_VARIABLES__
#define __SOME_HTML_NEEDED_VARIABLES__
char return_to_line[] = "\n\n"; // to separate between the header and html code in http response
#endif
#endif
#ifndef __LIBRARIES_INCLUDED__
#define __LIBRARIES_INCLUDES__
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#endif

#ifndef __HTTP_SERVER_FUNCTIONS__
#define __HTTP_SERVER_FUNCTIONS__
#ifdef __HTTP_SERVER_CONFIGURATION__

// defining a new socket
void define_socket();


//function to concatnate the http header to the page message :
void concatenate(char result_buffer [] , char message[]); // concatenate function will put result in result buffer buffer 

#endif
#endif
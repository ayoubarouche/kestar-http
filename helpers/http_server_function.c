#include "http_server_functions.h"

#ifndef __LIBRARIES_INCLUDED__
#define __LIBRARIES_INCLUDES__
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#endif

#ifdef __HTTP_SERVER_CONFIGURATION__

// defining a new socket
void define_socket()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
}

//function to concatnate the http header to the page message :
void concatenate(char result_buffer [] , char message[]) // concatenate function will put result in result buffer buffer 
{
    // get the length of message :
    int char_length = number_of_chars_to_allow_in_memory(strlen(message));
    char *message_length = (char *) malloc(sizeof(char) * char_length) ;
   // strcat(message_length , google);
    sprintf(message_length, "%d", strlen(message));
    // printf("the message length is : %s", message_length);
    // println();
    // //  the final message that will be sent to the client server :
    
    // // add the message length
    strcat(result_buffer,message_length);
    strcat(result_buffer , return_to_line);
    strcat(result_buffer , message);
    
}
#endif
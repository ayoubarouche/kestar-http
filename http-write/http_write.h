

#ifndef __SERVER_WRITE__
#define __SERVER_WRITE__


#ifndef __LIBRARIES_INCLUDED__
#define __LIBRARIES_INCLUDED__
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#endif


#ifdef __HTTP_SERVER_CONFIGURATION__

void send_to_client(int socket, char *message_to_send)
{
    write(socket, message_to_send, strlen(message_to_send));
}

#endif
#endif
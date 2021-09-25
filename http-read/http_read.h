
#ifndef __SERVER_READ__
#define __SERVER_READ__
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
void read_from_client(int socket, char *buffer)
{
    int valread = 0;

    // wait to get the message from the client
    while (valread <= 0)
    {
        valread = read(socket, buffer, BUFFER_SIZE);
        printf("the value of valread is : %d",valread);
        println();
    }
    

    return;
}
#endif
#endif
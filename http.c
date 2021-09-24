#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

// for the int value returned by the socket function :
int server_fd;

// variable to handle the address of our http server
struct sockaddr_in address;

// the size of the address
int addrlen = sizeof(address);
// the port used by the http server
const int PORT = 8080;

// will contains all the addresses of the http server clients
struct sockaddr client_addresses[10];

//will run through the client_addresses ;
int client_addresses_tour = 0;

//size of the buffer of messages received from the client

#define BUFFER_SIZE 30000


//the http header :
char *http_header = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: ";
char *return_to_line = "\n\n";

// defining a new socket
void define_socket()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
}
void println()
{
    printf("\n");
}

//function to send  hello messages for first tests :

void send_to_client(int socket, char *message_to_send)
{
    write(socket, message_to_send, strlen(message_to_send));
}

void read_from_client(int socket, char *buffer)
{
    int valread = 0;

    // wait to get the message from the client
    while (valread <= 0)
    {
        valread = read(socket, buffer, BUFFER_SIZE);
    }

    printf("the client : %s", buffer);
    println();
    printf("the size of message is : %d", sizeof(buffer));
    println();
    return; 
}
//function to converte int to char

//function to concatnate the http header to the page message :
char *concatenate(char *message)
{
    // get the length of message :
    
    char *message_length;
    sprintf(message_length, "%f", strlen(message));
    printf("the message length is : %s",message_length);
    println();
    //  the final message that will be sent to the client server :
    char *result;
    // add the http header
    strcpy(result, http_header);
    // add the message length
    strcat(result, message_length);
    // return to line
    strcat(result, return_to_line);
    // add the message
    strcat(result, message);
    free(message_length);
    println();
    printf("the message to sent is : %s",result);
    println();
    return result;
}

int main()
{
    // the socket of the client :
    int new_socket;

    // create the socket
    define_socket();

    if (server_fd < 0)
    {
        perror("cannot create the socket ");
        return 0;
    }

    // binding the socket

    // filling all the fields with zeroes of the sockadd_in struct
    memset(address.sin_zero, '\0', sizeof(address.sin_zero));

    // set the address family
    address.sin_family = AF_INET;

    // set the address to let the operating system
    //    to choice wich network interface to use by passing 0.0.0.0 address (INADDR_ANY)
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    // set the port to be used by our http server :
    address.sin_port = htons(PORT);

    // binding the socket :
    int binding_result = bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // test the binding result :
    if (binding_result < 0)
    {
        perror("bind failed !!!!");
        return 0;
    }

    // listening for incomming connections :
    if (listen(server_fd, 3) < 0)
    {
        perror("in listen");
        return 0;
    }
    while (1)
    {
        if (client_addresses_tour == 10)
        {
            printf("the server is full ");
            println();
            continue;
        }
        printf("waiting for a new connection");
        println();

        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addresses[client_addresses_tour], (socklen_t *)&addrlen)) < 0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        //after a successful connection with the client the client_addresses_tour will be incremented
        client_addresses_tour++;

        //create a process to work with that client
        if (fork() == 0)
        {

            // create a process for reading from the clien :
            // the parent process will used for sending to the client

            while (1)
            {
                char buffer[30000] = {0}; // this buffer will contains the message sent by the client :
                read_from_client(new_socket, buffer);
               
               //     char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n" + "\nHello world!";
                char * message = "hello world";
                char * result = "hello wrold from the server";
                send_to_client(new_socket, result);
                free(result);
            }
            close(new_socket);
            // this is for sending to the client :
        }
        // the server continue looking for connections
    }

    return 0;
}

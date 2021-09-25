#include "helpers/helpers.c"
#include "helpers/http_server.h"
#include "helpers/http_server_function.c"
#include "http-read/http_read.h"
#include "http-write/http_write.h"
#include "html_file_read.c"
#ifdef __HTTP_SERVER_CONFIGURATION__
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
                char buffer[40000] = {0}; // this buffer will contains the message sent by the client :
                read_from_client(new_socket, buffer);
                printf("the buffer is : %s",buffer);
              //  char *path = get_requested_path(buffer);
               // printf("the path is : %s", path);
                //char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
                char *message = render("html/index.html");
                //   char header[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: ";
                //   char last_values[] = "12\n\nHello zorld!";
                //   strcat(header , last_values);
                //  char * result = "hello wrold from the server";
                char result[] = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";

                // int mess_leng = (int)strlen(message);
                // printf("the message length is : %d",mess_leng);
                // sprintf(message_length, "%d", strlen(message));
                // strcat(result , message_length);
                // printf("%s", message_length);

                concatenate(result, message);
                send_to_client(new_socket, result);
                free(message);

                // send_to_client(new_socket , new_result);
            }
            close(new_socket);
            // this is for sending to the client :
        }
        // the server continue looking for connections
    }

    return 0;
}
#endif

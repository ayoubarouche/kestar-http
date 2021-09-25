.DEFAULT_GOAL := server
CC = gcc
sayhello :
	@echo "hello world"
all : server client
	@echo "server and client generated succeffly"
helpers : 
	${CC} helpers/helpers.c -o helpers
http_server_function : helpers
	${CC} helpers/http_server_function.c -o http_server_function
server : 
	${CC} http_server.c -o server
client :
	${CC} http_client.c -o client
clean :
	@echo "Cleaning up"
	rm server
	rm client
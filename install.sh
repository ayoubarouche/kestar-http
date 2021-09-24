#!/bin/bash
rm http_server
clear
echo "compiling the server"
gcc http.c -o http_server
echo "compiling the client"
gcc http_client.c -o http_client
echo "launch the server"
echo '-------------------------------'
./http_server
echo
echo

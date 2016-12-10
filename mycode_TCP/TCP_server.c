#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>


int main(){
	
	//variable to save the data, which we send to all the clients
	char server_message[256] = "you have reached the server";
	
	//socket for server	
	int server_socket;
	//to create socket, call socket function
	server_socket = socket(AF_INET, SOCK_STREAM,0);

	//define the server address
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // any ip address on the local machine

	//bind the socket to our specified IP and Port

	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	listen(server_socket, 5);
	
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	//send the message
	send(client_socket, server_message, sizeof(server_message),0);

	//close the socket
	close(server_socket);	
	return 0;
}

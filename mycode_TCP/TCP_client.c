#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> //to store address information

int main(){
	
	//create a socket for client
	int network_socket;

		//to create socket, call socket function from library file
	network_socket = socket(AF_INET, SOCK_STREAM, 0); 

	
	//Specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	
	//connect(socket,cast struct of server address_ and pass the pointers, size of the server address)
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	//check for error with the connection
	if (connection_status == -1){
		printf("there was an error making connection for the remote server \n \n");
	}
	
	//recieve data from the server
	//recv(socket, pointer variable-location to put actual data getting from the server,buffersize)
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	//print out the server's response
	printf("the sever sent the data : \" %s \"\n", server_response);

	close(network_socket);
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main() {

	char buf[256];
	char message[256];
    // create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	// send the message

	while(strcmp(buf, "exit") != 0 && strcmp(message, "exit") != 0) {
		recv(client_socket, &buf, sizeof(buf), 0);
		printf("Message Recieved: %s\n", buf);

        if (strcmp(buf, "exit") != 0) {
            printf("Enter Message to Send: ");
            scanf("%s", message);
            send(client_socket, message, sizeof(message), 0);
        }
    }

	// close the socket
	close(server_socket);
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
	
	char request[256];
	char buf[256];
	
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	
	while (strcmp(request, "exit") != 0 && strcmp(buf, "exit") != 0) {
		printf("Enter Message to Send: ");
		scanf("%s", &request);
		send(sock, request, sizeof(request), 0);
		
		if (strcmp(request, "exit") != 0) {
			printf("Message Received: ");
			recv(sock, &buf, sizeof(buf), 0);
			printf("%s\n", buf);
		}
	}
	
	close(sock);

	return 0;
}
#include "init.h"

int setup_server(unsigned int port) {
	struct sockaddr_in serv;
	int sock, comm;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (0 > sock) {
		/* return -1 if socket() failed */
		return -1;
	}
	serv.sin_family = AF_INET;
	serv.sin_port = htons(port);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	if (0 > bind(sock, (struct sockaddr*)&serv, sizeof(serv))) {
		/* return -2 if bind() failed */
		return -2;
	}/*
	listen(sock, 10);
	comm = accept(sock, (struct sockaddr*) NULL, NULL);
	*/
	return sock; /* return socket descriptor */
}
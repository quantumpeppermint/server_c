#include "init.h"
#include "log.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	pid_t process_id = 0;
	pid_t sid = 0;
	int sock = 0;
	/* create child process */
	process_id = fork();
	/* check if we've succesfuly forked */
	if (0 > process_id) {
		printf("fork failed\n");
		return -1;
	}
	/* daemonize here */
	if (0 < process_id) {
		printf("Child PID is %d, exiting parent process...\n", process_id);
		return 0;
	}
	/* create a new session & check it */
	sid = setsid();
	if (0 > sid) {
		return 1;
	}
	/* close standard io descriptors */ 
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	sock = setup_server(3000);
	if (0 > sock) {
		write_log(SERVER_LOG_ERROR, "couldn't create socket or bind, exiting");
		return 1;
	}
	write_log(SERVER_LOG_NOTICE, "server is up");
	while (1) {
		sleep(1);
		write_log(SERVER_LOG_NOTICE, "ok");
		/* this loop runs in background forever */
	}	
	return 0;

}

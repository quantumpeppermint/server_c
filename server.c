#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv) {
	pid_t process_id = 0;
	pid_t sid = 0;
	FILE *fp = NULL;
	long time_now = time(NULL);
	/* create child process */
	process_id = fork();
		if (0 > process_id) {
			printf("fork failed\n");
			return -1;
		}
		if (0 < process_id) {
			printf("Child PID is %d, exiting parent process...\n", process_id);
			return 0;
		}
		sid = setsid();
		if (0 > sid) {
			return 1;
		}
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		fp = fopen("server.log", "w+");
		while (1) {
			sleep(1);
			fprintf(fp, "%ld\n", time_now);
			fflush(fp);
			time_now = time(NULL);
		}	
	fclose(fp);
	return 0;

}

#define LOGFILE "server.log"
#include <stdio.h>

enum loglevel {
	SERVER_LOG_NOTICE,
	SERVER_LOG_WARN,
	SERVER_LOG_ERROR
};

void write_log(int level, char* log_text);
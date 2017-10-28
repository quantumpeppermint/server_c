#include "log.h"

void write_log(int level, char* log_text) {
	FILE *logfile_ptr = NULL;
	logfile_ptr = fopen(LOGFILE, "a+");
	switch(level) {
		case SERVER_LOG_NOTICE: fprintf(logfile_ptr, "NOTICE: %s\n", log_text); break;
		case SERVER_LOG_WARN: fprintf(logfile_ptr, "WARNING: %s\n", log_text); break;
		case SERVER_LOG_ERROR: fprintf(logfile_ptr, "ERROR: %s\n", log_text); break;
		default: fprintf(logfile_ptr, "ERROR: %s\n", log_text); break; /* by default, treat unknown log level as error */
	}
	fflush(logfile_ptr);
}
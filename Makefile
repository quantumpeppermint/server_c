all: init.o log.o server.o
	cc -o server init.o log.o server.o

init.o: init.c init.h
	cc -c init.c
log.o: log.c log.h
	cc -c log.c
server.o: server.c 
	cc -c server.c

clean:
	rm init.o log.o server.o *.log
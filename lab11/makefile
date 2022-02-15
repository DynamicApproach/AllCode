all: start_client

start_client: client_server.o
	gcc -o client_Server client_Server.o -g -Wall
	./client_Server
client_server.o: client_server.c
	gcc -c client_server.c -g -Wall

clean:
	rm -f client_server.o
	rm -f client_Server

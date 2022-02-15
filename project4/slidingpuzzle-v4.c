// This will be your main unit hosting your project's main() function which depending on the command line arguments will act as the game server or a game client.

//     If the first argument is -s, your program will run as a game server.
//         Your program should also accept a second optional argument in this case that determines the port for the server. If no port is provided, try to bind your server to default port 3490.
//         Your main() should call the server's function from its corresponding unit, passing the default/provided port number.
//     If the first argument is -c, your program will run as a game client.
//         Your program should also accept a second mandatory argument in this case that determines the host/IP for the server to connect to.
//         Your program should also accept a third optional argument that determines the port for the server. If no port is provided, try to connect to the server on the default port 3490.
//         Your main() should call the client's function from its corresponding unit, passing the host name/IP and the default/provided port number.
//     If no argument is provided, display a help message on standard error:

//     Running as server: slidingpuzzle-v4 -s [PORT]
//     Running as client: slidingpuzzle-v4 -c HOST [PORT]

#include <stdio.h>
#include <string.h>
// take 2 arguments for server and client
void serveraddr(char *port);
void server();
void client(char *host, char *port);
void clientNoPort(char *host);
int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    // if server
    if (argc == 2 && !strcmp(argv[1], "-s"))
    {
        // call server
        server();
    }
    else if (argc == 3 && !strcmp(argv[1], "-s"))
    {
        // call server with port
        serveraddr(argv[2]);
    }
    else if (argc == 2 && !strcmp(argv[1], "-c"))
    {
        // error no port or host
        fprintf(stderr, "Running as client: slidingpuzzle-v4 -c HOST [PORT]\n");
        fprintf(stderr, "Host is required to run client.\n");
    }
    else if (argc == 3 && !strcmp(argv[1], "-c"))
    {
        // call client with just host
        client(argv[2], "3490"); // TODO: remove other function, just call with argv[2] and port
        fprintf(stderr, "client port.\n");
    }
    else if (argc == 4 && !strcmp(argv[1], "-c"))
    {
        // call client with host and port
        client(argv[2], argv[3]);
        fprintf(stderr, "client host + port.\n");
    }
    else
    {
        // if no arguments
        fprintf(stderr, "No arguments given. To run this program:\n");
        fprintf(stderr, "Running as server: slidingpuzzle-v4 -c [PORT]\n");
        fprintf(stderr, "Running as client: slidingpuzzle-v4 -c HOST [PORT]\n");
    }

    return 0;
}
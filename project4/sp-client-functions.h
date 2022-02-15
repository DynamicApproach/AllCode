
/* Prototypes for the functions */
int getStatusClient(int sockfd);
struct gameboard recvBoardClient(int sockfd, struct gameboard *board);
char* createBoardStringClient(struct gameboard *board, int size);
void printBoardClient(struct gameboard *board);
void send_row_colClient( int row, int col,int sockfd);
char* recvFromServerClient(int sockfd);
void sendToServer(int sockfd,char *message );
void move(int sockfd, struct gameboard *board);
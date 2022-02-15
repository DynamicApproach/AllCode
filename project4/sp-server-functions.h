
int checkWin(struct gameboard *game);

int sendStatus(int sockfd, int status);
int getStatusServ(int sockfd);

char *createBoardString(struct gameboard *board, int size);
void send_row_col(int row, int col, int sockfd);
void sendToClient(int sockfd, char *command);
struct gameboard recvBoardServ(int sockfd, struct gameboard *gb);
void sendBoardServ(int sockfd, struct gameboard *gb);

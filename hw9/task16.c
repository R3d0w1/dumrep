#include "stdio.h"
#define SIZE 8
void read_to_index(int* socket);
int main()
{
    int socket[2],target;
    int chessboard[SIZE][SIZE]={0};
    for(int i=0;i<SIZE;i++)
    {int j=0;
        if(i%2!=0){j=1;}
            for(;j<SIZE;j+=2)
            {
                chessboard[i][j]=1;
            }
    }
    read_to_index(socket);
    chessboard[socket[0]][socket[1]];
    if (chessboard[socket[0]][socket[1]])
    {
        printf("%s","BLACK\n");
    }
    else printf("%s","WHITE\n");
    return 0;
}
void read_to_index(int* socket)
{
    socket[0] = (int)getchar()-65;
    socket[1] = (int)getchar()-49;
}
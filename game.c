#include "game.h"

void initboard(char board [][COLS], int rows, int cols, char set)
{
    int x,y = 0;
    for(x = 0; x < rows; x++)
    {
        for(y = 0; y < cols ; y++)
        {
            board[x][y] = set;
        }
    }
}

void printboard(const char board[][COLS], int rows, int cols)
{
    int x,y = 0;
    for(x = 0; x < rows; x++)
    {
        for(y = 0; y < cols ; y++)
        {
            printf("%c ", board[x][y]); 
        }
        printf("\n");
    }
}

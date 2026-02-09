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

void printboard(const char board[][COLS], int row, int col)
{
    int x,y = 0;
    for(y = 0; y <= col; y++) { 
        printf("%d ", y);
    }
    printf("\n");
    for(x = 1; x <= row; x++)
    {
        printf("%d ", x);
        for(y = 1; y <= col; y++)
        {
            printf("%c ", board[x][y]); 
        }
        printf("\n");
    }
    printf("\n");
}

void setboard(char board[][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand()%row + 1;
        int y = rand()%col + 1;
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

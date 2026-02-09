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

void exclude(char realboard[][COLS], char showboard[][COLS], int row, int col)
{
    printf("enter exclude success\n");
    int x ,y = 0;
    int number = (ROW*COL) - EASY_COUNT;
    while(number)
    {
        printf("select the position: ");
        scanf("%d%d", &x, &y);
        if(x >= 1 && x <= col && y >= 1 && y <=row)
        {
            if(realboard[x][y] == '1') {
                printf("you died\n");  
                printboard(realboard, ROW, COL);
                break;
            }
            else {
                int count = get_count(realboard, x, y);
                showboard[x][y] = count + '0';
                printboard(showboard, ROW, COL);
                number--;
            }    
        }
        else { printf("坐标非法");}
    }
    
    if(number == 0)
    {
        printf("win\n");
        printboard(realboard, ROW, COL);
    }
}


int get_count(char realboard[][COLS], int x, int y)
{
    return realboard[x-1][y-1] + realboard[x-1][y] + realboard[x-1][y+1] + 
    realboard[x][y-1] + realboard[x][y+1] + 
    realboard[x+1][y-1] + realboard[x+1][y] + realboard[x+1][y+1] - 8* '0';
}
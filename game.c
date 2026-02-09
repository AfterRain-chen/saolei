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
    printf("enter exclude successfully\n");
    int x ,y = 0;
    int number = getxing(showboard, row, col);
    while(number > EASY_COUNT)
    {
        printf("select the position: ");
        scanf("%d%d", &x, &y);
        if(x >= 1 && x <= row && y >= 1 && y <=col)
        {
            if(realboard[x][y] == '1') {
                printf("you died\n");  
                printboard(realboard, ROW, COL);
                break;
            }
            else {
                //最难的递归部分
                ExpandBoard(realboard, showboard, x , y);
                
                printboard(showboard, ROW, COL);
                number = getxing(showboard,row , col);
                printf("%d\n",number);
            }    
        }
        else { printf("坐标非法");}
    }
    
    if(number == EASY_COUNT)
    {
        printf("win\n");
        printboard(realboard, ROW, COL);
    }
}

void ExpandBoard(char realboard[][COLS], char showboard[][COLS], int x, int y)
{
    printf("enter ExpandBoard successfully\n");
    printf("%d %d\n",x,y);
    //越界检查
    if(x < 1 || x >= ROWS || y < 1 || y >=COLS ) 
    {   printf("越界\n");
        return; 
    }
    if(showboard[x][y] == ' ') {printf("已处理\n"); return; }; 
    //计算雷数
    int count = get_count(realboard, x, y);
    //
    if(count > 0) {
        showboard[x][y] = count + '0';
    }
    //
    else {
        showboard[x][y] = ' ';
        int i , j = 0;
        for(i = x-1; i <= x+1; i++)
        {
            for(j = y-1; j <= y+1; j++) 
            {
                if(i == x && j == y) { continue; }
                ExpandBoard(realboard, showboard, i, j);
                printf("enter other\n");
            }
        }
    }
    //
}

int get_count(char realboard[][COLS], int x, int y)
{
    return realboard[x-1][y-1] + realboard[x-1][y] + realboard[x-1][y+1] + 
    realboard[x][y-1] + realboard[x][y+1] + 
    realboard[x+1][y-1] + realboard[x+1][y] + realboard[x+1][y+1] - 8* '0';
}

int getxing(char showboard[][COLS], int row, int col)
{
    int count = 0;
    for(int i = 1; i <= row; i ++)
    {
        for(int j = 1; j <= col ; j++)
        {
            if(showboard[i][j] == '*')
            count++;
        }
    }
    return count;
}
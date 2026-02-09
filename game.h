#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS (ROW + 2)
#define COLS (COL + 2)
#define EASY_COUNT 10

void initboard(char board[][COLS], int rows, int cols, char set);
void printboard(const char board[][COLS], int row, int col);
void setboard(char board[][COLS], int row, int col);
void exclude(char realboard[][COLS], char showboard[][COLS], int row, int col);
int get_count(char realboard[][COLS], int x, int y);
void ExpandBoard(char realboard[][COLS], char showboard[][COLS], int x, int y);
int getxing(char showboard[][COLS], int row, int col);
#endif
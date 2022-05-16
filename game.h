//
//  game.h
//  扫雷test
//
//  Created by 曾爷666 on 2022/4/10.
//
#include <stdlib.h>
#ifndef game_h
#define game_h
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
void INITboard(char board[ROWS][COLS],int rows,int cols,char set);
#include <stdio.h>
void Displayboard(char board[ROW][COL],int row,int col);
void SetMind(char board[ROW][COL],int row,int col );
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col);
#endif /* game_h */

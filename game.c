//
//  game.c
//  扫雷test
//
//  Created by 曾爷666 on 2022/4/10.
//

#include "game.h"
void INITboard(char board[ROWS][COLS],int rows,int cols,char set)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            board[i][j]=set;
        }
    }
}
void Displayboard(char board[ROW][COL],int row,int col)
{
    //打印列号
    int i=0;
    int j=0;
    for (i=0; i<=col ; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for ( i=1; i<=row; i++)
    {
        //打印行号
            printf("%d ",i);
        for ( j=1; j<=col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
void SetMind(char board[ROW][COL],int row,int col )
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row+1;
        int y = rand() % col+1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
     return mine[x-1][y]+ mine[x+1][y]+ mine[x-1][y-1]+ mine[x-1][y+1]+ mine[x][y+1]+
    mine[x+1][y+1]+ mine[x][y-1]+ mine[x+1][y-1]-8*'0';
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
    int x;
    int y;
    int win=0;
    while (win<row*col+EASY_COUNT)
    {
        printf("请输入坐标\n");
        scanf("%d%d",&x,&y);
        if (x>=1&&x<=row&&y>=1&&y<=col)
        {
        //坐标合法
            //1.中弹
            if (mine[x][y]=='1')
            {
                printf("很遗憾，你被炸死了QAQ\n");
                Displayboard(mine,ROW,COL);
                break;
            }
            else//不是雷还得判断周围雷数
            {
                win ++;
                int count = get_mine_count(mine , x,y);
                show[x][y]=count +'0';
                Displayboard(show,ROW,COL);
            }
            
        }
        else
        {
            printf("坐标违法，重新输入\n");
        }
    }
    if (win==row*col+EASY_COUNT)
    {
        printf("恭喜排雷成功 \n");
        Displayboard(mine,ROW,COL);
    }
}

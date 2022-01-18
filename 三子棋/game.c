#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>



void InitBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < ROW; i++)
	{
		//1/打印一行数据
		for (j = 0; j < col; j++)
		{
			if (j< col - 1)printf(" %c |", board[i][j]);
			else printf(" %c \n", board[i][j]);
		}
		//2/打印分隔行
		if (i < col - 1)
		for (j = 0; j < col; j++)	
		{						
				if (j< col - 1) printf("---|");
				else printf("---\n");			
		}
	}
}

void Playermove(char board[ROW][COL])
{
	int x=1;
	int y;
	printf("玩家走>\n");
	do
	{		
		printf("请输入要走的坐标:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; break;
			}
				else
					printf("该位置有棋子，请重新选择位置\n");			          
		}
		else
		printf("坐标非法，请重新输入/n");
	} while (1);
}

void Computermove(char board[ROW][COL])
{
	int x;
	int y;
	printf("电脑走>\n");
	while (1)
	{
		x = rand() % COL;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}	
}

int Ping(char board[ROW][COL])
{
	int i;
	int j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL])
{
	int i;
	//行一致查找
	for (i = 0; i < ROW; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && board[i][0] != ' ')
			return board[i][1];
	}
	//列一致查找
	for (i = 0; i < COL; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[0][i] != ' ')
			return board[1][i];
	}
	//斜方向查找
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[0][0] != ' ')
		return board[0][0];
	else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[2][0] != ' ')
		return board[0][2];
	//平局查找
	else if (Ping(board) == 1)return 'Q';
	else return 'C';
}
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
		//1/��ӡһ������
		for (j = 0; j < col; j++)
		{
			if (j< col - 1)printf(" %c |", board[i][j]);
			else printf(" %c \n", board[i][j]);
		}
		//2/��ӡ�ָ���
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
	printf("�����>\n");
	do
	{		
		printf("������Ҫ�ߵ�����:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; break;
			}
				else
					printf("��λ�������ӣ�������ѡ��λ��\n");			          
		}
		else
		printf("����Ƿ�������������/n");
	} while (1);
}

void Computermove(char board[ROW][COL])
{
	int x;
	int y;
	printf("������>\n");
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
	//��һ�²���
	for (i = 0; i < ROW; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && board[i][0] != ' ')
			return board[i][1];
	}
	//��һ�²���
	for (i = 0; i < COL; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[0][i] != ' ')
			return board[1][i];
	}
	//б�������
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[0][0] != ' ')
		return board[0][0];
	else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[2][0] != ' ')
		return board[0][2];
	//ƽ�ֲ���
	else if (Ping(board) == 1)return 'Q';
	else return 'C';
}
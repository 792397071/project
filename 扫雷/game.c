#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROWS][COLS], char set)

	{
		int i = 0;
		int j = 0;
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS; j++)
			{
				board[i][j] = set;
			}
		}
	}
void DisplayBoard(char board[ROWS][COLS])
{
	int i;
	int j;
	int k=1;
	for (i = 0; i <= COL; i++)
		printf("%d ",i);
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", k);
		k++;
		for (j = 1; j <= COL; j++)
		{
			printf("%c ",board[i][j]);

		}
		printf("\n");
	}

}

void SetMine(char board[ROWS][COLS])
{
	int lei = EASY_COUNT;
	int i;
	int x;
	int y;
	while (lei)
	{	
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y]=='0')
		{
			board[x][y] = '1';
			lei--;
		}
	}
}
int get(char board1[ROWS][COLS],int x, int y)
{
	return board1[x - 1][y] +
		board1[x - 1][y - 1] +
		board1[x][y - 1] +
		board1[x + 1][y - 1] +
		board1[x + 1][y] +
		board1[x + 1][y + 1] +
		board1[x][y + 1] +
		board1[x - 1][y + 1] - 8 * '0';
}


void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS])
{
	int x;
	int y;
	int ret;
	int win = 0;
	while (win < ROW*COL - EASY_COUNT)
	{
		printf("请输入排查雷的坐标：");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= ROW))
		{
			//踩雷
			if (board1[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(board1, x, y);
				break;
			}
			//非雷
			else
			{
				win++;
				ret = get(board1, x, y);
				board2[x][y] = ret + '0';
				DisplayBoard(board2, x, y);
			}
		}
		else
		{
			printf("坐标非法，请重新输入>\n");
		}
	}
	if (win == ROW*COL - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(board1);
	}
}
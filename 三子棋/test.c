#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("******1.    paly      ********\n");
	printf("******0.    exit      ********\n");
	printf("******************************\n");
}
void game()
{
//定义结果
	char ret = 0;
//定义棋盘信息
	char board[ROW][COL];
//初始化棋盘
	InitBoard(board, ROW, COL);
//打印棋盘
	DisplayBoard(board, ROW, COL);
//开始下棋	
	while (1)
	{
        //玩家下棋
		Playermove(board);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board);
		if (ret != 'C')
			break;
		//电脑下棋
		Computermove(board);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board);
		if (ret != 'C')		
			break;
	}
	if (ret == '*')
		printf("玩家获胜\n");
	else if (ret == '#')
		printf("电脑获胜\n");
	else if (ret=='Q')
		printf("平局\n");

}
void test()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("请选择(1/0):  \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break; 
		case 0:printf("退出游戏\n"); break; 
		default:printf("选择错误\n"); break; 
		}
	} while (input);
}

int main()
{

	test();
	return 0;

}

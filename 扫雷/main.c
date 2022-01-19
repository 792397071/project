#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("*********  1 play  *********\n");
	printf("*********  0 exit  *********\n");
	printf("****************************\n");
}

void game()
{
	char board1[ROWS][COLS];
	char board2[ROWS][COLS];
	//初始化棋盘
	InitBoard(board1, '0');
	InitBoard(board2,'*');
	//展示棋盘
	DisplayBoard(board2);
	//布置雷
	SetMine(board1);
	DisplayBoard(board1);
	//排雷开始、
	FindMine(board1, board2);

}

void test()
{
	int input;
	

	do{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf(""); break;
		default:printf("输入错误，请重新选择>\n");
		}

	} while(input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
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
//������
	char ret = 0;
//����������Ϣ
	char board[ROW][COL];
//��ʼ������
	InitBoard(board, ROW, COL);
//��ӡ����
	DisplayBoard(board, ROW, COL);
//��ʼ����	
	while (1)
	{
        //�������
		Playermove(board);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board);
		if (ret != 'C')
			break;
		//��������
		Computermove(board);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board);
		if (ret != 'C')		
			break;
	}
	if (ret == '*')
		printf("��һ�ʤ\n");
	else if (ret == '#')
		printf("���Ի�ʤ\n");
	else if (ret=='Q')
		printf("ƽ��\n");

}
void test()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("��ѡ��(1/0):  \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break; 
		case 0:printf("�˳���Ϸ\n"); break; 
		default:printf("ѡ�����\n"); break; 
		}
	} while (input);
}

int main()
{

	test();
	return 0;

}

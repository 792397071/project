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
	//��ʼ������
	InitBoard(board1, '0');
	InitBoard(board2,'*');
	//չʾ����
	DisplayBoard(board2);
	//������
	SetMine(board1);
	DisplayBoard(board1);
	//���׿�ʼ��
	FindMine(board1, board2);

}

void test()
{
	int input;
	

	do{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf(""); break;
		default:printf("�������������ѡ��>\n");
		}

	} while(input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], char set);
void DisplayBoard(char board[ROWS][COLS]);
void SetMine(char board[ROWS][COLS]);
void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS]);

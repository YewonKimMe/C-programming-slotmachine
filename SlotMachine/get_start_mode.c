#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9999

#include <stdio.h>
#include "get_start_mode.h"

/*
	���ϸ�:	get_start_mode.c
	����: ���� ���� ��带 �Է¹ް� ó���ϴ� �Լ�
	����: Function
		@Param	: void
		@Return	: 1(int), 0(int), 9999(int)
	������: 2024-05-01
*/
extern const char* blue;
extern const char* red;
extern const char* reset;
int get_start_mode(void)
{
	int game_mode;
	while (1) // Ư�� ���̽��� �Է� ���� ���� ���� �ݺ�
	{
		printf("������ �����Ͻ÷��� Ű������ [%s1%s]�� �Է��� �ּ���. �����Ͻ÷��� [%s0%s]�� �Է��� �ּ���.\n>>", blue, reset, red, reset);
		scanf("%d", &game_mode);
		if (game_mode == START_GAME) // ���� ����
			return START_GAME;
		else if (game_mode == END_GAME) // ���� ����
			return END_GAME;
		else if (game_mode == TEST_MODE) // �׽�Ʈ ��� - 9999 �Է�
			return TEST_MODE;
		else
		{
			printf("�ùٸ��� ���� �Է� �Դϴ�.\n");
			while (getchar() != '\n');// �Է� ���� ����
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9999

#include <stdio.h>
#include "get_start_mode.h"

int get_start_mode()
{
	int game_mode;
	while (1) // Ư�� ���̽��� �Է� ���� ���� ���� �ݺ�
	{
		printf("������ �����Ͻ÷��� Ű������ [1]�� �Է��� �ּ���. �����Ͻ÷��� [0]�� �Է��� �ּ���.\n>>");
		scanf("%d", &game_mode);
		if (game_mode == START_GAME) // ���� ����
			return START_GAME;
		else if (game_mode == END_GAME) // ���� ����
			return END_GAME;
		else if (game_mode == TEST_MODE) // �׽�Ʈ ���-9��
			return TEST_MODE;
		else
		{
			printf("�ùٸ��� ���� �Է� �Դϴ�.\n");
			while (getchar() != '\n');// �Է� ���� ����
		}
	}
}
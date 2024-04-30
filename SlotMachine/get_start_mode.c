#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9999

#include <stdio.h>
#include "get_start_mode.h"

int get_start_mode()
{
	int game_mode;
	while (1) // 특정 케이스를 입력 받을 동안 무한 반복
	{
		printf("게임을 시작하시려면 키보드의 [1]을 입력해 주세요. 종료하시려면 [0]을 입력해 주세요.\n>>");
		scanf("%d", &game_mode);
		if (game_mode == START_GAME) // 게임 시작
			return START_GAME;
		else if (game_mode == END_GAME) // 게임 종료
			return END_GAME;
		else if (game_mode == TEST_MODE) // 테스트 모드-9번
			return TEST_MODE;
		else
		{
			printf("올바르지 않은 입력 입니다.\n");
			while (getchar() != '\n');// 입력 버퍼 비우기
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9999

#include <stdio.h>
#include "get_start_mode.h"

/*
	파일명:	get_start_mode.c
	설명: 게임 시작 모드를 입력받고 처리하는 함수
	종류: Function
		@Param	: void
		@Return	: 1(int), 0(int), 9999(int)
	수정일: 2024-05-01
*/
extern const char* blue;
extern const char* red;
extern const char* reset;
int get_start_mode(void)
{
	int game_mode;
	while (1) // 특정 케이스를 입력 받을 동안 무한 반복
	{
		printf("게임을 시작하시려면 키보드의 [%s1%s]을 입력해 주세요. 종료하시려면 [%s0%s]을 입력해 주세요.\n>>", blue, reset, red, reset);
		scanf("%d", &game_mode);
		if (game_mode == START_GAME) // 게임 시작
			return START_GAME;
		else if (game_mode == END_GAME) // 게임 종료
			return END_GAME;
		else if (game_mode == TEST_MODE) // 테스트 모드 - 9999 입력
			return TEST_MODE;
		else
		{
			printf("올바르지 않은 입력 입니다.\n");
			while (getchar() != '\n');// 입력 버퍼 비우기
		}
	}
}
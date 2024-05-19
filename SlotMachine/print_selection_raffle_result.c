#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>

extern const char* green;
extern const char* yellow;
extern const char* reset;

/*
	파일명:	print_selection_raffle_result.c
	설명:	유저 배팅 배열, 생성된 배열 두개를 인자로 받아 일치 여부를 확인하고 출력하는 함수
	종류:	Function
	수정일: 2024-05-19
*/
void print_selection_raffle_result(int user_bat[3], int prob_random_selected[3])
{
	printf("\t\t===================================\n");
	printf("유저 배팅 숫자: ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("| >> %s%d%s << | ", yellow, user_bat[i], reset);
		else
			printf("| >> %d << | ", user_bat[i]);
	}
	printf("\n");

	printf("추첨 숫자 결과: ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("| >> %s%d%s << | ", yellow, prob_random_selected[i], reset);
		else
			printf("| >> %d << | ", prob_random_selected[i]);
	}
	printf("\n");
	printf("\t\t===================================\n");
}

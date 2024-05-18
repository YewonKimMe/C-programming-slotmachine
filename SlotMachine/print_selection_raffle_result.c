#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>

extern const char* green;
extern const char* yellow;
extern const char* reset;
void print_selection_raffle_result(int user_bat[3], int prob_random_selected[3])
{
	printf("유저 배팅 숫자: [ ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("%s%d%s ", yellow, user_bat[i], reset);
		else
			printf("%d ", user_bat[i]);
	}
	printf("]\n");

	printf("추첨 숫자 결과: [ ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("%s%d%s ", yellow, prob_random_selected[i], reset);
		else
			printf("%d ", prob_random_selected[i]);
	}
	printf("]\n");
}

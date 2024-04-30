#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY_JACKPOT 0.001
#define BOUNDARY_THREE_MATCH 0.01
#define BOUNDARY_TWO_MATCH 0.05
#define BOUNDARY_ONE_MATCH 0.2

#include <stdio.h>
#include "handle_random_event.h"

/*
	���ϸ�:	handle_random_event.c
	����: Ȯ���������� ���ڷ� �޾� ���� ��谪 ���� ��÷ ó�� �� ��� ������ �ϴ� �Լ�
	����: Function
		@Param	: proability(double), money(int*)
		@Return	: int
	������: 2024-05-01
*/
int handle_random_event(double probability, int* money)
{
	printf("[arg Ȯ����]: %.10f, [PERCENTAGE]: %.2f%%\n", probability, probability * 100);
	if (0 < probability && probability < BOUNDARY_JACKPOT) { // 0 < x < jackpot
		printf("���� ��÷, Ȯ����: %.5f\n", probability);
	}
	else if (BOUNDARY_JACKPOT <= probability && probability < BOUNDARY_THREE_MATCH) { // jackpot <= x < three_match
		printf("3�� ��ġ, Ȯ����: %.5f\n", probability);
	}
	else if (BOUNDARY_THREE_MATCH <= probability && probability < BOUNDARY_TWO_MATCH) {
		printf("2�� ��ġ, Ȯ����: %.5f\n", probability);
	}
	else if (BOUNDARY_TWO_MATCH <= probability && probability < BOUNDARY_ONE_MATCH) {
		printf("1�� ��ġ, Ȯ����: %.5f\n", probability);
	}
	else {
		printf("0�� ��ġ, Ȯ����: %.5f\n", probability);
	}
	return 0;
}
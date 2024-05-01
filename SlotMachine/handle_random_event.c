#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY_JACKPOT 0.005
#define BOUNDARY_THREE_MATCH 0.01
#define BOUNDARY_TWO_MATCH 0.05
#define BOUNDARY_ONE_MATCH 0.3
#define JACKPOT_RATIO 20
#define THREEMATCH_RATIO 10
#define TWOMATCH_RATIO 3
#define ONEMATCH_RATIO 1


#include <stdio.h>
#include "handle_random_event.h"
#include "check_boundary.h"

/*
	���ϸ�:	handle_random_event.c
	����: Ȯ���������� ���ڷ� �޾� ���� ��谪 ���� ��÷ ó�� �� ��� ������ �ϴ� �Լ�
	����: Function
		@Param	: proability(double), money(int*)
		@Return	: int
	������: 2024-05-01
*/
int handle_random_event(double probability, int* money, int betting_money)
{
	printf("[arg Ȯ����]: %.10f, [PERCENTAGE]: %.2f%%\n", probability, probability * 100);
	int boundary_result = check_boundary(probability);

	switch (boundary_result)
	{
	case 0:
		printf("���� ��÷, Ȯ����: %.5f\n", probability);
		*money += betting_money * JACKPOT_RATIO;
		break;
	case 1:
		printf("3�� ��ġ, Ȯ����: %.5f\n", probability);
		*money += betting_money * THREEMATCH_RATIO;
		break;
	case 2:
		printf("2�� ��ġ, Ȯ����: %.5f\n", probability);
		*money += betting_money * TWOMATCH_RATIO;
		break;
	case 3:
		printf("1�� ��ġ, Ȯ����: %.5f\n", probability);
		*money += betting_money * ONEMATCH_RATIO;
		break;
	case 4:
		printf("0�� ��ġ, Ȯ����: %.5f\n", probability);
		break;
	default:
		break;
	}
	return 0;
}
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

extern const char* red;
extern const char* green;
extern const char* blue;
extern const char* yellow;
extern const char* orange;
extern const char* reset;

/*
	���ϸ�:	handle_random_event.c
	����: Ȯ���������� ���ڷ� �޾� ���� ��谪 ���� ��÷ ó�� �� ��� ������ �ϴ� �Լ�
	����: Function
		@Param	: proability(double), money(int*)
		@Return	: int
	������: 2024-05-01
*/
int handle_random_event(double probability, int prob_code, int* money, int betting_money, int * acc_money)
{
	printf("%s��÷ ��� >> %s", orange, reset);
	switch (prob_code)
	{
	case 0:
		printf("%s[$$$$$$ >>> @ ���� ��÷ @ <<< $$$$$$]%s\n", yellow, reset);
		*money += betting_money * JACKPOT_RATIO;
		*money += *acc_money;
		*acc_money = 0;
		break;
	case 1:
		printf("%s3�� ��ġ%s\n", blue, reset);
		*money += betting_money * THREEMATCH_RATIO;
		break;
	case 2:
		printf("%s2�� ��ġ%s\n", green, reset);
		*money += betting_money * TWOMATCH_RATIO;
		break;
	case 3:
		printf("%s1�� ��ġ%s\n", green, reset);
		*money += betting_money * ONEMATCH_RATIO;
		break;
	case 4:
		printf("%s0�� ��ġ%s\n", red, reset);
		break;
	default:
		break;
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY_JACKPOT 0.005
#define BOUNDARY_THREE_MATCH 0.01
#define BOUNDARY_TWO_MATCH 0.05
#define BOUNDARY_ONE_MATCH 0.3

#include <stdio.h>
#include "handle_random_event.h"
#include "check_boundary.h"

/*
	파일명:	handle_random_event.c
	설명: 확률변수값을 인자로 받아 변수 경계값 별로 추첨 처리 및 상금 가감을 하는 함수
	종류: Function
		@Param	: proability(double), money(int*)
		@Return	: int
	수정일: 2024-05-01
*/
int handle_random_event(double probability, int* money)
{
	printf("[arg 확률값]: %.10f, [PERCENTAGE]: %.2f%%\n", probability, probability * 100);
	int boundary_result = check_boundary(probability);

	switch (boundary_result)
	{
	case 0:
		printf("잭팟 당첨, 확률값: %.5f\n", probability);
		break;
	case 1:
		printf("3개 일치, 확률값: %.5f\n", probability);
		break;
	case 2:
		printf("2개 일치, 확률값: %.5f\n", probability);
		break;
	case 3:
		printf("1개 일치, 확률값: %.5f\n", probability);
		break;
	case 4:
		printf("0개 일치, 확률값: %.5f\n", probability);
		break;
	default:
		break;
	}
	return 0;
}
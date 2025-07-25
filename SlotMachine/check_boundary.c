#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY_JACKPOT 0.001 // 0.1%
#define BOUNDARY_THREE_MATCH 0.011 // 1%
#define BOUNDARY_TWO_MATCH 0.111 // 10%
#define BOUNDARY_ONE_MATCH 0.461 // 35%
#define BOUNDARY_MAX 1.0

#define CODE_JACKPOT 0
#define CODE_THREE_MATCH 1
#define CODE_TWO_MATCH 2
#define CODE_ONE_MATCH 3
#define CODE_NO_MATCH 4

#include <stdio.h>
#include "check_boundary.h"

const int code_jackpot = CODE_JACKPOT;
const int code_three_match = CODE_THREE_MATCH;
const int code_two_match = CODE_TWO_MATCH;
const int code_one_match = CODE_ONE_MATCH;
const int code_no_match = CODE_NO_MATCH;
/*
	파일명:	check_boundary.c
	설명: 랜덤값을 받아 경계값에 따른 조건 처리, 확률 관련 함수(확률 경계값이 이곳에 선언되어 있음)
	종류: Function
		@Param	: probability(double)
		@Return	: 0(int) or 1(int) or 2(int) or 3(int) or 4(int) 
	수정일: 2024-05-01
*/
int check_boundary(double probability)
{
	if (0 < probability && probability <= BOUNDARY_JACKPOT) { // 0 < x <= BOUNDARY_JACKPOT
		return CODE_JACKPOT;
	}
	else if (BOUNDARY_JACKPOT < probability && probability <= BOUNDARY_THREE_MATCH) { // BOUNDARY_JACKPOT < x <= BOUNDARY_THREE_MATCH
		return CODE_THREE_MATCH;
	}
	else if (BOUNDARY_THREE_MATCH < probability && probability <= BOUNDARY_TWO_MATCH) { // BOUNDARY_THREE_MATCH < x <= BOUNDARY_TWO_MATCH
		return CODE_TWO_MATCH;
	}
	else if (BOUNDARY_TWO_MATCH < probability && probability <= BOUNDARY_ONE_MATCH) { // BOUNDARY_TWO_MATCH < x <= BOUNDARY_ONE_MATCH
		return CODE_ONE_MATCH;
	}
	else if (BOUNDARY_ONE_MATCH < probability && probability <= 1){ // BOUNDARY_ONE_MATCH < x <= 1
		return CODE_NO_MATCH;
	}
}

// 경계값을 획득하는 함수
double get_boundary_const(int code)
{
	switch (code) {
	case CODE_JACKPOT:
		return BOUNDARY_JACKPOT;

	case CODE_THREE_MATCH:
		return BOUNDARY_THREE_MATCH;

	case CODE_TWO_MATCH:
		return BOUNDARY_TWO_MATCH;

	case CODE_ONE_MATCH:
		return BOUNDARY_ONE_MATCH;

	case CODE_NO_MATCH:
		return BOUNDARY_MAX - (BOUNDARY_JACKPOT + BOUNDARY_THREE_MATCH + BOUNDARY_TWO_MATCH + BOUNDARY_ONE_MATCH);

	default:
		return -1; // 예기치 않은 코드에 대한 반환 값
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "boundary_test.h"
#include "check_boundary.h"
#include "print_test_message.h"

void check(int target, int code, char* message);

/*
	파일명:	boundary_test.c
	설명: check_boundary.c 의 check_boundary() 테스트 
	종류: Function
	수정일: 2024-05-02
*/
void boundary_test()
{
	const double jackpot = 0.0009;
	const double three_match = 0.0015;
	const double two_match = 0.016;
	const double one_match = 0.116;
	const double zero_match = 0.5;

	print_test_message("확률값에 따른 경계 범위 조건 판정 테스트");
	print_test_message("[JACKPOT], [3_MATCH], [2_MATCH], [1_MATCH], [0_MATCH] TEST");
	check(check_boundary(jackpot), 0, "[JACKPOT]-확률값에 따른 범위 조건 판정이 유효합니다.");
	check(check_boundary(three_match), 1, "[3_MATCH]-확률값에 따른 범위 조건 판정이 유효합니다.");
	check(check_boundary(two_match), 2, "[2_MATCH]-확률값에 따른 범위 조건 판정이 유효합니다.");
	check(check_boundary(one_match), 3, "[1_MATCH]-확률값에 따른 범위 조건 판정이 유효합니다.");
	check(check_boundary(zero_match), 4, "[0_MATCH]-확률값에 따른 범위 조건 판정이 유효합니다.");
}

void check(int target, int code, char* message)
{
	if (target == code)
		print_test_success_message(message);
	else
		print_test_fail_message("확률값에 따른 범위 조건 판정이 유효하지 않습니다.", target);
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "boundary_test.h"
#include "check_boundary.h"
#include "print_test_message.h"

void check(int target, int code);

void boundary_test()
{
	double jackpot = 0.0009;
	double three_match = 0.0015;
	double two_match = 0.016;
	double one_match = 0.116;
	double zero_match = 0.5;

	print_test_message("Ȯ������ ���� ��� ���� ���� ���� �׽�Ʈ");
	print_test_message("[JACKPOT], [3_MATCH], [2_MATCH], [1_MATCH], [0_MATCH] TEST");
	check(check_boundary(jackpot), 0);
	check(check_boundary(three_match), 1);
	check(check_boundary(two_match), 2);
	check(check_boundary(one_match), 3);
	check(check_boundary(zero_match), 4);
}

void check(int target, int code)
{
	if (target == code)
		print_test_success_message("Ȯ������ ���� ���� ���� ������ ��ȿ�մϴ�.");
	else
		print_test_fail_message("Ȯ������ ���� ���� ���� ������ ��ȿ���� �ʽ��ϴ�.");
}
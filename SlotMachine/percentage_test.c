#define _CRT_SECURE_NO_WARNINGS
#define TEST_NUM 100000000
#define BOUNDARY_JACKPOT 0.001 // 0.1%
#define BOUNDARY_THREE_MATCH 0.011 // 1%
#define BOUNDARY_TWO_MATCH 0.111 // 10%
#define BOUNDARY_ONE_MATCH 0.461 // 35%

#define BOUNDARY_MAX 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "percentage_test.h"
#include "get_random_value.h"
#include "print_test_message.h"
#include "test_time_cal.h"
#include "check_boundary.h"
#include "convert_money.h"

void check_result(double target, double first, double second, char* success_message, char* fail_message);

void percentage_test(void)
{
	clock_t start, end;
	double cpu_time_used;

	int jackpot = 0;
	int three = 0;
	int two = 0;
	int one = 0;
	int zero = 0;
	int try_num = TEST_NUM;
	const char* converted_try_num = convert_money(&try_num);
	printf("\n");
	print_test_message("Ȯ�� ���� �׽�Ʈ");
	print_test_message("�ݺ� ������ ���� �� �������� Ȯ�� �׽�Ʈ�� �����մϴ�.");
	print_test_message_str("���� Ƚ�� (ȸ)", converted_try_num);
	print_test_message("���� �׽�Ʈ�� ������ �Դϴ�...\n");

	start = clock();

	for (int i = 0; i < TEST_NUM; i++) {
		double double_percent = get_random_value(); // ������ ����
		//printf("%.50f\n", double_percent);
		int boundary_code = check_boundary(double_percent);
		//printf("%d\n", boundary_code);

		if (boundary_code == 0)
			jackpot++;
		else if (boundary_code == 1)
			three++;
		else if (boundary_code == 2)
			two++;
		else if (boundary_code == 3)
			one++;
		else
			zero++;
	}

	end = clock();
	//printf("%d\n",jackpot);
	double jackpot_percent = ((double)jackpot / (double)TEST_NUM) * 100;
	double three_percent = ((double)three / (double)TEST_NUM) * 100;
	double two_percent = ((double)two / (double)TEST_NUM) * 100;
	double one_percent = ((double)one / (double)TEST_NUM) * 100;
	double zero_percent = ((double)zero / (double)TEST_NUM) * 100;
	// �׽�Ʈ ��� ���
	print_percent_test_result("�׽�Ʈ ���_JACKPOT", jackpot, TEST_NUM, jackpot_percent);
	print_percent_test_result("�׽�Ʈ ���_3_MATCH", three, TEST_NUM, three_percent);
	print_percent_test_result("�׽�Ʈ ���_2_MATCH", two, TEST_NUM, two_percent);
	print_percent_test_result("�׽�Ʈ ���_1_MATCH", one, TEST_NUM, one_percent);
	print_percent_test_result("�׽�Ʈ ���_0_MATCH", zero, TEST_NUM, zero_percent);

	check_result(jackpot_percent, 0, BOUNDARY_JACKPOT * 100, "JACKPOT Ȯ���� ���� �����Դϴ�.", "JACKPOT Ȯ���� ���� ���� ���Դϴ�.");
	check_result(three_percent, BOUNDARY_JACKPOT * 100, BOUNDARY_THREE_MATCH * 100, "3�� ��ġ Ȯ���� ���� �����Դϴ�.", "3�� ��ġ Ȯ���� ���� ���� ���Դϴ�.");
	check_result(two_percent, BOUNDARY_THREE_MATCH * 100, BOUNDARY_TWO_MATCH * 100, "2�� ��ġ Ȯ���� ���� �����Դϴ�.", "2�� ��ġ Ȯ���� ���� ���� ���Դϴ�.");
	check_result(one_percent, BOUNDARY_TWO_MATCH * 100, BOUNDARY_ONE_MATCH * 100, "1�� ��ġ Ȯ���� ���� �����Դϴ�.", "1�� ��ġ Ȯ���� ���� ���� ���Դϴ�.");
	check_result(zero_percent, BOUNDARY_ONE_MATCH * 100, BOUNDARY_MAX*100, "0�� ��ġ Ȯ���� ���� �����Դϴ�.", "0�� ��ġ Ȯ���� ���� ���� ���Դϴ�.");
	
	cpu_time_used = test_time_cal(start, end);
	print_test_time(cpu_time_used);
}

/*
	first < target <= second �˻� �Լ�
	second�� check_boundary�� ��谪
*/
void check_result(double target, double first, double second, char* success_message, char* fail_message)
{
	if (target > first && target <= second) // ��ǥȮ�� target ���� Ȯ������ first���� ũ�� Ȯ������ second ���� ���ų� ���� ��� 
		print_test_success_message(success_message);
	else
		print_test_fail_message(fail_message);
}
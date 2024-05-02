#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "print_test_message.h"
#include "test_time_cal.h"
#include "convert_test.h"
#include "convert_money.h"

/*
	���ϸ�:	convert_test.c
	����: convert_money.c �� convert_money() ��� �׽�Ʈ
	����: Function
	������: 2024-05-02
*/
void convert_test()
{
	int money = 1000000;
	char expected_str[] = "1,000,000";
	clock_t start, end;
	double cpu_time_used;

	//printf("\n");
	print_test_message("���� õ���� �޸� ��� �׽�Ʈ");
	print_test_message_num("�ʱ� ������", money);

	start = clock(); //���� �ð�

	const char* converted_money = convert_money(&money);
	print_test_message_str("���� �� ���ڿ�", converted_money);

	end = clock(); //���� �ð�
	cpu_time_used = test_time_cal(start, end);
	if (strcmp(converted_money, expected_str) == 0) //��ȯ�� ���ڿ� ���� ���ڿ��� ��ġ�ϴ� ���
		print_test_success_message("���氪�� ���󰪰� ��ġ�մϴ�.");
	else
		print_test_fail_message("���氪�� ���󰪰� ��ġ���� �ʽ��ϴ�.");

	print_test_time(cpu_time_used);
}
#define _CRT_SECURE_NO_WARNINGS
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <stdio.h>

/*
	���ϸ�:	print_test_message.c
	����: �׽�Ʈ ���� �� �ʿ��� ��� �޼��� �Լ� ����
	����: Function
	������: 2024-05-02
*/

// print_test_message: �⺻ ��� ���, ���ڿ� ������ message�� �޾� �׽�Ʈ ��� ��Ŀ� ���� ���
void print_test_message(char* message)
{
	printf("[TEST]\t\t%s\n", message);
}

// print_test_message_num: ���ڿ� ������ message�� ���� num�� �޾� �׽�Ʈ ��� ��Ŀ� ���� ���
void print_test_message_num(char* message, int num)
{
	printf("[TEST]\t\t%s = %d\n", message, num);
}

// print_test_message_str: ���ڿ� ������ message�� ���ڿ� str�� �޾� �׽�Ʈ ��� ��Ŀ� ���� ���
void print_test_message_str(char* message, char* str)
{
	printf("[TEST]\t\t%s = %s\n", message, str);
}

// print_test_result_message: ���ڿ� ������ message�� �޾� �׽�Ʈ ��� �޼����� ���
void print_test_result_message(char* message)
{
	printf("[TEST_RESULT]\t%s\n", message);
}

// print_test_success_message: ���ڿ� ������ message�� �޾� �׽�Ʈ ���� �޼����� �ʷϻ����� ���
void print_test_success_message(char* message)
{
	printf("%s[TEST_SUCCESS]\t%s%s\n", GREEN, message, RESET);
}

// print_test_fail_message: ���ڿ� ������ message�� �޾� �׽�Ʈ ���� �޼����� ���������� ���
void print_test_fail_message(char* message, double value)
{
	printf("%s[TEST_FAIL]\t%s%f%s\n", RED, message, value, RESET);
}

// print_percent_test_result: ���ڿ� ������ message, ���� cnt, ���� attmpt_cnt, �Ǽ� percentage�� �޾� Ȯ���׽�Ʈ ����� ���
void print_percent_test_result(char* message, int cnt, int attempt_cnt, double percentage)
{
	printf("[TEST_RESULT]\t%s,\t���� Ƚ��={%10d},\t�õ� Ƚ��={%d},\tȮ�� �׽�Ʈ ���={%-12.9f %% �� %-5.2f %%}\n", message, cnt, attempt_cnt, percentage, percentage);
}

// print_test_time: �Ǽ� used_time�� �޾� �׽�Ʈ ���� �ð��� ���信 ���߾� �Ҽ��� 8�ڸ����� ���
void print_test_time(double used_time)
{
	printf("[TEST_EX_TIME]\t�׽�Ʈ ����ð�: %.8f (��)\n", used_time);
}

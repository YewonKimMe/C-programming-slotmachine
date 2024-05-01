#define _CRT_SECURE_NO_WARNINGS
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <stdio.h>

void print_test_message(char* message)
{
	printf("[TEST]\t\t%s\n", message);
}

void print_test_message_num(char* message, int num)
{
	printf("[TEST]\t\t%s = %d\n", message, num);
}

void print_test_message_str(char* message, char* str)
{
	printf("[TEST]\t\t%s = %s\n", message, str);
}

void print_test_result_message(char* message)
{
	printf("[TEST_RESULT]\t%s\n", message);
}

void print_test_success_message(char* message)
{
	printf("%s[TEST_SUCCESS]\t%s%s\n", GREEN, message, RESET);
}

void print_test_fail_message(char* message)
{
	printf("%s[TEST_FAIL]\t%s%s\n", RED, message, RESET);
}

void print_percent_test_result(char* message, int cnt, int attempt_cnt, double percentage)
{
	printf("[TEST_RESULT]\t%s,\t등장 횟수={%10d},\t시도 횟수={%d},\t확률 테스트 결과={%-5.2f %%}\n", message, cnt, attempt_cnt, percentage);
}

void print_test_time(double used_time)
{
	printf("[TEST_TIME]\t테스트 수행시간: %.3f (초)\n", used_time);
}

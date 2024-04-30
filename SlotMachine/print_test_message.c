#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_test_message(char* message)
{
	printf("[TEST]\t%s\n", message);
}

void print_test_result_format(char* message, int cnt, int attempt_cnt, double percentage)
{
	printf("[TEST_RESULT] %s,\t등장 횟수={%10d},\t시도 횟수={%d},\t확률 테스트 결과={%.4f %%}\n", message, cnt, attempt_cnt, percentage);
}
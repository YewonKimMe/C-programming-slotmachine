#define _CRT_SECURE_NO_WARNINGS
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <stdio.h>

/*
	파일명:	print_test_message.c
	설명: 테스트 수행 시 필요한 출력 메세지 함수 모음
	종류: Function
	수정일: 2024-05-02
*/

// print_test_message: 기본 출력 양식, 문자열 포인터 message를 받아 테스트 출력 양식에 맞춰 출력
void print_test_message(char* message)
{
	printf("[TEST]\t\t%s\n", message);
}

// print_test_message_num: 문자열 포인터 message와 정수 num을 받아 테스트 출력 양식에 맞춰 출력
void print_test_message_num(char* message, int num)
{
	printf("[TEST]\t\t%s = %d\n", message, num);
}

// print_test_message_str: 문자열 포인터 message와 문자열 str을 받아 테스트 출력 양식에 맞춰 출력
void print_test_message_str(char* message, char* str)
{
	printf("[TEST]\t\t%s = %s\n", message, str);
}

// print_test_result_message: 문자열 포인터 message를 받아 테스트 결과 메세지를 출력
void print_test_result_message(char* message)
{
	printf("[TEST_RESULT]\t%s\n", message);
}

// print_test_success_message: 문자열 포인터 message를 받아 테스트 성공 메세지를 초록색으로 출력
void print_test_success_message(char* message)
{
	printf("%s[TEST_SUCCESS]\t%s%s\n", GREEN, message, RESET);
}

// print_test_fail_message: 문자열 포인터 message를 받아 테스트 실패 메세지를 빨간색으로 출력
void print_test_fail_message(char* message, double value)
{
	printf("%s[TEST_FAIL]\t%s%f%s\n", RED, message, value, RESET);
}

// print_percent_test_result: 문자열 포인터 message, 정수 cnt, 정수 attmpt_cnt, 실수 percentage를 받아 확률테스트 결과를 출력
void print_percent_test_result(char* message, int cnt, int attempt_cnt, double percentage)
{
	printf("[TEST_RESULT]\t%s,\t등장 횟수={%10d},\t시도 횟수={%d},\t확률 테스트 결과={%-12.9f %% ≒ %-5.2f %%}\n", message, cnt, attempt_cnt, percentage, percentage);
}

// print_test_time: 실수 used_time을 받아 테스트 수행 시간을 포멧에 맞추어 소수점 8자리까지 출력
void print_test_time(double used_time)
{
	printf("[TEST_EX_TIME]\t테스트 수행시간: %.8f (초)\n", used_time);
}

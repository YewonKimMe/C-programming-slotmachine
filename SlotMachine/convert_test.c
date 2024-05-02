#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "print_test_message.h"
#include "test_time_cal.h"
#include "convert_test.h"
#include "convert_money.h"

/*
	파일명:	convert_test.c
	설명: convert_money.c 의 convert_money() 기능 테스트
	종류: Function
	수정일: 2024-05-02
*/
void convert_test()
{
	int money = 1000000;
	char expected_str[] = "1,000,000";
	clock_t start, end;
	double cpu_time_used;

	//printf("\n");
	print_test_message("숫자 천단위 콤마 기능 테스트");
	print_test_message_num("초기 정수값", money);

	start = clock(); //시작 시간

	const char* converted_money = convert_money(&money);
	print_test_message_str("변경 후 문자열", converted_money);

	end = clock(); //종료 시간
	cpu_time_used = test_time_cal(start, end);
	if (strcmp(converted_money, expected_str) == 0) //변환된 숫자와 예상 문자열이 일치하는 경우
		print_test_success_message("변경값이 예상값과 일치합니다.");
	else
		print_test_fail_message("변경값이 예상값과 일치하지 않습니다.");

	print_test_time(cpu_time_used);
}
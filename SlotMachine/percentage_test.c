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
#include <math.h>

#include "percentage_test.h"
#include "get_random_value.h"
#include "print_test_message.h"
#include "test_time_cal.h"
#include "check_boundary.h"
#include "convert_money.h"

void check_result(double target, double first, double second, char* success_message, char* fail_message);

/*
	파일명:	percentage_test.c
	설명: 선택지별 예측 확률과 실제 확률을 확인하는 테스트 코드
	종류: Function
	수정일: 2024-05-02
*/
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
	//printf("\n");
	print_test_message("확률 변수 테스트");
	print_test_message("반복 실행을 통한 각 선택지의 확률 테스트를 시작합니다.");
	print_test_message_str("수행 횟수 (회)", converted_try_num);
	print_test_message("현재 테스트가 실행중 입니다...\n");

	start = clock();

	for (int i = 0; i < TEST_NUM; i++) {
		double double_percent = get_random_value(); // 랜덤값 생성
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
	// 테스트 결과 출력
	print_percent_test_result("테스트 결과_JACKPOT", jackpot, TEST_NUM, jackpot_percent);
	print_percent_test_result("테스트 결과_3_MATCH", three, TEST_NUM, three_percent);
	print_percent_test_result("테스트 결과_2_MATCH", two, TEST_NUM, two_percent);
	print_percent_test_result("테스트 결과_1_MATCH", one, TEST_NUM, one_percent);
	print_percent_test_result("테스트 결과_0_MATCH", zero, TEST_NUM, zero_percent);

	check_result(jackpot_percent, 0, BOUNDARY_JACKPOT * 100, "[JACKPOT]-확률이 예상값 범위입니다.", "[JACKPOT]-확률이 예상값 범위 밖입니다. 오차범위(%p): ");
	check_result(three_percent, BOUNDARY_JACKPOT * 100, BOUNDARY_THREE_MATCH * 100, "[3_MATCH]-확률이 예상값 범위입니다.", "[3_MATCH]-확률이 예상값 범위 밖입니다. 오차범위(%p): ");
	check_result(two_percent, BOUNDARY_THREE_MATCH * 100, BOUNDARY_TWO_MATCH * 100, "[2_MATCH]-확률이 예상값 범위입니다.", "[2_MATCH]-확률이 예상값 범위 밖입니다. 오차범위(%p): ");
	check_result(one_percent, BOUNDARY_TWO_MATCH * 100, BOUNDARY_ONE_MATCH * 100, "[1_MATCH]-확률이 예상값 범위입니다.", "[1_MATCH]-확률이 예상값 범위 밖입니다. 오차범위(%p): ");
	check_result(zero_percent, BOUNDARY_ONE_MATCH * 100, BOUNDARY_MAX*100, "[0_MATCH]-확률이 예상값 범위입니다.", "[0_MATCH]-확률이 예상값 범위 밖입니다. 오차범위(%p): ");
	
	cpu_time_used = test_time_cal(start, end);
	print_test_time(cpu_time_used);
}

/*
	check_result

	first < target <= second 검사 함수
	first, second는 check_boundary의 경계값 * 100
*/
void check_result(double target, double first, double second, char* success_message, char* fail_message)
{
	if (target > first && target <= second) // 목표확률 target 값이 확률구간 first보다 크고 확률구간 second 보다 같거나 작은 경우 
		print_test_success_message(success_message);
	else
	{
		double diff = second - target; // 확률이 경계값 보다 큰 경우 설정확률 오차 발생, 오차 %p
		print_test_fail_message(fail_message, fabs(diff));
	}
}
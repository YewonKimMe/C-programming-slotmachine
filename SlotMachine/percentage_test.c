#define _CRT_SECURE_NO_WARNINGS
#define TEST_NUM 200000000

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "percentage_test.h"
#include "get_random_value.h"
#include "print_test_message.h"
#include "check_boundary.h"

void percentage_test(void)
{
	int jackpot = 0;
	int three = 0;
	int two = 0;
	int one = 0;
	int zero = 0;
	print_test_message("확률 변수 테스트\n");
	print_test_message("반복 실행을 통한 각 선택지의 확률 테스트를 시작합니다.\n");
	print_test_message("현재 테스트가 실행중 입니다...\n");

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
	//printf("%d\n",jackpot);
	double jackpot_percent = ((double)jackpot / (double)TEST_NUM) * 100;
	double three_percent = ((double)three / (double)TEST_NUM) * 100;
	double two_percent = ((double)two / (double)TEST_NUM) * 100;
	double one_percent = ((double)one / (double)TEST_NUM) * 100;
	double zero_percent = ((double)zero / (double)TEST_NUM) * 100;
	// 테스트 결과 출력
	print_test_result_format("테스트 결과_JACKPOT", jackpot, TEST_NUM, jackpot_percent);
	print_test_result_format("테스트 결과_THREE_MATCH", three, TEST_NUM, three_percent);
	print_test_result_format("테스트 결과_TWO_MATCH", two, TEST_NUM, two_percent);
	print_test_result_format("테스트 결과_ONE_MATCH", one, TEST_NUM, one_percent);
	print_test_result_format("테스트 결과_ZERO_MATCH", zero, TEST_NUM, zero_percent);
}
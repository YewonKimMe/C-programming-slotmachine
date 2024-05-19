#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "make_selection.h"
#include "print_test_message.h"

extern const int code_jackpot; // 0
extern const int code_three_match; // 1
extern const int code_two_match; // 2
extern const int code_one_match; // 3
extern const int code_no_match; // 4

int check_array_make(int array1[3], int array2[3], int code, int* count_7) {
	make_selection(code, array1, array2); // 결과 코드, 유저 입력 배열, 생성될 배열
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (array2[i] == 7)
			(*count_7)++;

		if (array1[i] == array2[i])
			count++;
	}
	return count;
}

void make_selection_test(void)
{
	int user_input[3] = { 3, 4, 1 }; // 유저가 입력한 값, 0~5 아무거나.
	int to_be_made[3] = { 0, 0, 0 }; // 생성될 배열
	int count_7 = 0;

	print_test_message("추첨 숫자 생성/일치 테스트");

	check_array_make(user_input, to_be_made, code_jackpot, &count_7); // 잭팟 검증
	printf("count7=%d\n", count_7);
	if (count_7 == 3)
		print_test_success_message("잭팟 추첨 숫자 검증 성공");
	else
		print_test_fail_message_default("잭팟 추첨 숫자 검증 실패");

	if (check_array_make(user_input, to_be_made, code_three_match, &count_7) == 3)
		print_test_success_message("3개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("3개 숫자 일치 검증 실패");

	if (check_array_make(user_input, to_be_made, code_two_match, &count_7) == 2)
		print_test_success_message("2개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("2개 숫자 일치 검증 실패");

	if (check_array_make(user_input, to_be_made, code_one_match, &count_7) == 1)
		print_test_success_message("1개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("1개 숫자 일치 검증 실패");

	if (check_array_make(user_input, to_be_made, code_no_match, &count_7) == 0)
		print_test_success_message("0개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("0개 숫자 일치 검증 실패");
}
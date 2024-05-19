#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "make_selection.h"
#include "print_test_message.h"

extern const int code_jackpot; // 0
extern const int code_three_match; // 1
extern const int code_two_match; // 2
extern const int code_one_match; // 3
extern const int code_no_match; // 4
extern const char* green;
extern const char* yellow;
extern const char* reset;

/*
	두 개의 배열을 입력받아 일치 여부를 확인하여 출력
*/
void print_two_array(int array1[3], int array2[3], char* message) {
	print_test_result_message(message);
	print_test_result_message("유저 입력값");
	for (int i = 0; i < 3; i++) {
		if (array1[i] == array2[i])
			printf("%s%d%s ", green, array1[i], reset);
		else
			printf("%d ", array1[i]);
	}
	printf("\n");
	print_test_result_message("추첨 생성값");
	for (int i = 0; i < 3; i++) {
		if (array1[i] == array2[i])
			printf("%s%d%s ", green, array2[i], reset);
		else
			printf("%d ", array2[i]);
	}
	printf("\n\n");
}

/*
	조건 code에 따라 배열 일치 여부 및 잭팟 여부를 검증
*/
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
/*
	파일명:	make_selection_test.c
	설명: 유저가 입력한 값 3개와 추첨으로 생성된 값 3개가 확률 코드에 따라 일치하는지 확인하는 테스트 코드
	종류: Function
	수정일: 2024-05-19
*/
void make_selection_test(void)
{
	int user_input[3] = { 3, 4, 1 }; // 유저가 입력한 값, 0~5 아무거나.
	int to_be_made[3] = { 0, 0, 0 }; // 생성될 배열
	int count_7 = 0;

	print_test_message("추첨 숫자 생성/일치 테스트_순서 고려(default)");

	check_array_make(user_input, to_be_made, code_jackpot, &count_7); // 잭팟 검증

	if (count_7 == 3)
		print_test_success_message("잭팟 추첨 숫자 검증 성공");
	else
		print_test_fail_message_default("잭팟 추첨 숫자 검증 실패");
	print_two_array(user_input, to_be_made, "잭팟 테스트 결과"); // 잭팟 테스트 케이스 출력

	if (check_array_make(user_input, to_be_made, code_three_match, &count_7) == 3) // 3개 일치 검증
		print_test_success_message("3개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("3개 숫자 일치 검증 실패");
	print_two_array(user_input, to_be_made, "3개 일치 테스트 결과"); // 3개 일치 테스트 케이스 출력

	if (check_array_make(user_input, to_be_made, code_two_match, &count_7) == 2) // 2개 일치 검증
		print_test_success_message("2개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("2개 숫자 일치 검증 실패");
	print_two_array(user_input, to_be_made, "2개 일치 테스트 결과"); // 2개 일치 테스트 케이스 출력

	if (check_array_make(user_input, to_be_made, code_one_match, &count_7) == 1) // 1개 일치 검증
		print_test_success_message("1개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("1개 숫자 일치 검증 실패");
	print_two_array(user_input, to_be_made, "1개 일치 테스트 결과"); // 1개 일치 테스트 케이스 출력

	if (check_array_make(user_input, to_be_made, code_no_match, &count_7) == 0) // 0개 일치 검증
		print_test_success_message("0개 숫자 일치 검증 성공");
	else
		print_test_fail_message_default("0개 숫자 일치 검증 실패");
	print_two_array(user_input, to_be_made, "0개 일치 테스트 결과"); // 0개 일치 테스트 케이스 출력
}
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
	�� ���� �迭�� �Է¹޾� ��ġ ���θ� Ȯ���Ͽ� ���
*/
void print_two_array(int array1[3], int array2[3], char* message) {
	print_test_result_message(message);
	print_test_result_message("���� �Է°�");
	for (int i = 0; i < 3; i++) {
		if (array1[i] == array2[i])
			printf("%s%d%s ", green, array1[i], reset);
		else
			printf("%d ", array1[i]);
	}
	printf("\n");
	print_test_result_message("��÷ ������");
	for (int i = 0; i < 3; i++) {
		if (array1[i] == array2[i])
			printf("%s%d%s ", green, array2[i], reset);
		else
			printf("%d ", array2[i]);
	}
	printf("\n\n");
}

/*
	���� code�� ���� �迭 ��ġ ���� �� ���� ���θ� ����
*/
int check_array_make(int array1[3], int array2[3], int code, int* count_7) {
	make_selection(code, array1, array2); // ��� �ڵ�, ���� �Է� �迭, ������ �迭
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
	���ϸ�:	make_selection_test.c
	����: ������ �Է��� �� 3���� ��÷���� ������ �� 3���� Ȯ�� �ڵ忡 ���� ��ġ�ϴ��� Ȯ���ϴ� �׽�Ʈ �ڵ�
	����: Function
	������: 2024-05-19
*/
void make_selection_test(void)
{
	int user_input[3] = { 3, 4, 1 }; // ������ �Է��� ��, 0~5 �ƹ��ų�.
	int to_be_made[3] = { 0, 0, 0 }; // ������ �迭
	int count_7 = 0;

	print_test_message("��÷ ���� ����/��ġ �׽�Ʈ_���� ���(default)");

	check_array_make(user_input, to_be_made, code_jackpot, &count_7); // ���� ����

	if (count_7 == 3)
		print_test_success_message("���� ��÷ ���� ���� ����");
	else
		print_test_fail_message_default("���� ��÷ ���� ���� ����");
	print_two_array(user_input, to_be_made, "���� �׽�Ʈ ���"); // ���� �׽�Ʈ ���̽� ���

	if (check_array_make(user_input, to_be_made, code_three_match, &count_7) == 3) // 3�� ��ġ ����
		print_test_success_message("3�� ���� ��ġ ���� ����");
	else
		print_test_fail_message_default("3�� ���� ��ġ ���� ����");
	print_two_array(user_input, to_be_made, "3�� ��ġ �׽�Ʈ ���"); // 3�� ��ġ �׽�Ʈ ���̽� ���

	if (check_array_make(user_input, to_be_made, code_two_match, &count_7) == 2) // 2�� ��ġ ����
		print_test_success_message("2�� ���� ��ġ ���� ����");
	else
		print_test_fail_message_default("2�� ���� ��ġ ���� ����");
	print_two_array(user_input, to_be_made, "2�� ��ġ �׽�Ʈ ���"); // 2�� ��ġ �׽�Ʈ ���̽� ���

	if (check_array_make(user_input, to_be_made, code_one_match, &count_7) == 1) // 1�� ��ġ ����
		print_test_success_message("1�� ���� ��ġ ���� ����");
	else
		print_test_fail_message_default("1�� ���� ��ġ ���� ����");
	print_two_array(user_input, to_be_made, "1�� ��ġ �׽�Ʈ ���"); // 1�� ��ġ �׽�Ʈ ���̽� ���

	if (check_array_make(user_input, to_be_made, code_no_match, &count_7) == 0) // 0�� ��ġ ����
		print_test_success_message("0�� ���� ��ġ ���� ����");
	else
		print_test_fail_message_default("0�� ���� ��ġ ���� ����");
	print_two_array(user_input, to_be_made, "0�� ��ġ �׽�Ʈ ���"); // 0�� ��ġ �׽�Ʈ ���̽� ���
}
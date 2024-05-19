#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>

extern const char* green;
extern const char* yellow;
extern const char* reset;

/*
	���ϸ�:	print_selection_raffle_result.c
	����:	���� ���� �迭, ������ �迭 �ΰ��� ���ڷ� �޾� ��ġ ���θ� Ȯ���ϰ� ����ϴ� �Լ�
	����:	Function
	������: 2024-05-19
*/
void print_selection_raffle_result(int user_bat[3], int prob_random_selected[3])
{
	printf("\t\t===================================\n");
	printf("���� ���� ����: ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("| >> %s%d%s << | ", yellow, user_bat[i], reset);
		else
			printf("| >> %d << | ", user_bat[i]);
	}
	printf("\n");

	printf("��÷ ���� ���: ");
	for (int i = 0; i < 3; i++) {
		if (user_bat[i] == prob_random_selected[i])
			printf("| >> %s%d%s << | ", yellow, prob_random_selected[i], reset);
		else
			printf("| >> %d << | ", prob_random_selected[i]);
	}
	printf("\n");
	printf("\t\t===================================\n");
}

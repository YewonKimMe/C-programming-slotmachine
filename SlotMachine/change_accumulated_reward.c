#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
	���ϸ�:	change_accumulated_reward.c
	����:	���� �ݾ��� �����ϴ� �Լ�, ���� ������ �����ϰ� ���ŵ� �����ݾ��� �ٽ� �ۼ��Ͽ� ������ �����ϴ� �Լ�
	����:	Function
	������: 2024-05-19
*/
int change_accumulated_reward(int exist_acc_money, int use_money, char* file_name)
{
	int new_accumulated_reward = exist_acc_money + use_money;
	FILE* fp = NULL;

	if (remove(file_name) == -1)
		printf("%s �� ������ �� �����ϴ�.\n", file_name);

	fp = fopen(file_name, "a");

	// ���ο� ���� �ݾ� �ۼ�
	fprintf(fp, "%d\n", new_accumulated_reward);

	fclose(fp);

	return new_accumulated_reward; // ���ο� ���� �ݾ� return;
	
	
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "get_random_value.h"
void set_srand(void);
/*
	���ϸ�:	get_random_value.c
	����:	�Ǽ� x, 0<x<1 ������ double type�� Ȯ�� ������ ��ȯ�ϴ� �Լ�
	����:	Function
		@Param	: void
		@Return	: double
	������: 2024-05-01
*/
static int flag = 1;
double get_random_value(void) 
{
	set_srand();
	double random_num = (double)rand() / (RAND_MAX + 1.0); // 0 < x < 1 ������ �Ǽ� ����
	return random_num;
}

void set_srand(void)
{
	if (flag == 1) { // ���α׷��� ����� ���� �õ尪�� ���� 1ȸ�� �����ǵ��� üũ
		srand((unsigned)time(NULL));
		flag = 0; // ���� ���� ������ 0���� ���õǾ� ���α׷� ���� ���� �õ尪 ���� ������ ȣ����� ����
	}
}
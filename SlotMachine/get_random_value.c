#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "get_random_value.h"
#include "moneyUnitConvertor.h"

/*
	���ϸ�:	get_random_value.c
	����: �ڿ��� x, 0<x<1 ������ double type�� Ȯ�� ������ ��ȯ�ϴ� �Լ�
	����: Function
		@Param	: void
		@Return	: double
	������: 2024-05-01
*/
double get_random_value(void) 
{
	srand((unsigned)time(NULL));
	double random_num = (double)rand() / (RAND_MAX + 1.0);
	printf("[DEBUG]���� ������: %.6f\n", random_num);
	return random_num;
}
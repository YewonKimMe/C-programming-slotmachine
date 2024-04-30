#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "get_random_value.h"
#include "moneyUnitConvertor.h"

/*
	파일명:	get_random_value.c
	설명: 자연수 x, 0<x<1 사이의 double type의 확률 변수를 반환하는 함수
	종류: Function
		@Param	: void
		@Return	: double
	수정일: 2024-05-01
*/
double get_random_value(void) 
{
	srand((unsigned)time(NULL));
	double random_num = (double)rand() / (RAND_MAX + 1.0);
	printf("[DEBUG]생성 랜덤값: %.6f\n", random_num);
	return random_num;
}
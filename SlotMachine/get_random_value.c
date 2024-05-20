#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "get_random_value.h"
void set_srand(void);
/*
	파일명:	get_random_value.c
	설명:	실수 x, 0<x<1 사이의 double type의 확률 변수를 반환하는 함수
	종류:	Function
		@Param	: void
		@Return	: double
	수정일: 2024-05-01
*/
static int flag = 1;
double get_random_value(void) 
{
	set_srand();
	double random_num = (double)rand() / (RAND_MAX + 1.0); // 0 < x < 1 사이의 실수 생성
	return random_num;
}

void set_srand(void)
{
	if (flag == 1) { // 프로그램이 실행될 동안 시드값을 최초 1회만 설정되도록 체크
		srand((unsigned)time(NULL));
		flag = 0; // 정적 전역 변수가 0으로 세팅되어 프로그램 종료 까지 시드값 설정 로직이 호출되지 않음
	}
}
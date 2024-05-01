#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
double test_time_cal(double start, double end)
{
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // 수행시간 계산
	return cpu_time_used;
}
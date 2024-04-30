#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "get_random_value.h"
#include "moneyUnitConvertor.h"

double get_random_value(void) 
{
	srand(time(NULL));
	double random_num = (double)rand() / (RAND_MAX + 1.0);
	return random_num;
}
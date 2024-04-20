#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "moneyUnitConvertor.h"
/*
	파일명: moneyUnivConvertor.c
	설명: 정수 money를 인자로 받아서 문자열 배열로 변경하고 천단위 마다 콤마(,)를 붙여 반환하는 함수
	종류: Function
*/
const char* moneyUnitConvertor(int *money) {
	char* str_money = malloc(64);
	char buffer[64];
	int mod;
	sprintf(buffer, "%d", *money);

	int buffer_len = strlen(buffer);
	mod = buffer_len % 3;
	
	int c = 0;
	for (int i = 0; i < buffer_len; i++) {
		if (i > 0 && i % 3 == mod)
			str_money[c++] = ',';
		str_money[c++] = buffer[i];
	}
	str_money[c] = '\0'; // 널 종료 문자 추가
	return str_money;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "convert_money.h"
/*
	파일명: convert_money.c
	설명: 정수 money를 인자로 받아서 문자열 배열로 변경하고 천단위 마다 콤마(,)를 붙여 반환하는 함수
	종류: Function
		@Param: *money(int*)
		@Return: str_money(char*)
	수정일: 2024-04-20
*/
const char* convert_money(int *money) {
	char* str_money = malloc(64);
	char buffer[64];
	int mod;
	sprintf(buffer, "%d", *money); // 정수 money를 넣어 문자열 배열 buffer 에 할당

	int buffer_len = strlen(buffer); // 버퍼의 길이
	mod = buffer_len % 3; // 3자리 마다 콤마를 붙여주기 위해 버퍼길이를 3으로 나눈 나머지
	
	int charIndexPosition = 0;
	for (int i = 0; i < buffer_len; i++) {
		if (i > 0 && i % 3 == mod) // index가 0보다 크고 index를 3으로 나눈 나머지가 
			str_money[charIndexPosition++] = ',';
		str_money[charIndexPosition++] = buffer[i];
	}
	str_money[charIndexPosition] = '\0'; // 널 종료 문자 추가
	return str_money;
}
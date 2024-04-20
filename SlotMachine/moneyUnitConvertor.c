#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "moneyUnitConvertor.h"
/*
	���ϸ�: moneyUnivConvertor.c
	����: ���� money�� ���ڷ� �޾Ƽ� ���ڿ� �迭�� �����ϰ� õ���� ���� �޸�(,)�� �ٿ� ��ȯ�ϴ� �Լ�
	����: Function
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
	str_money[c] = '\0'; // �� ���� ���� �߰�
	return str_money;
}
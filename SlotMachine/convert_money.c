#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "convert_money.h"
/*
	���ϸ�: convert_money.c
	����: ���� money�� ���ڷ� �޾Ƽ� ���ڿ� �迭�� �����ϰ� õ���� ���� �޸�(,)�� �ٿ� ��ȯ�ϴ� �Լ�
	����: Function
		@Param: *money(int*)
		@Return: str_money(char*)
	������: 2024-04-20
*/
const char* convert_money(int *money) {
	char* str_money = malloc(64);
	char buffer[64];
	int mod;
	sprintf(buffer, "%d", *money); // ���� money�� �־� ���ڿ� �迭 buffer �� �Ҵ�

	int buffer_len = strlen(buffer); // ������ ����
	mod = buffer_len % 3; // 3�ڸ� ���� �޸��� �ٿ��ֱ� ���� ���۱��̸� 3���� ���� ������
	
	int charIndexPosition = 0;
	for (int i = 0; i < buffer_len; i++) {
		if (i > 0 && i % 3 == mod) // index�� 0���� ũ�� index�� 3���� ���� �������� 
			str_money[charIndexPosition++] = ',';
		str_money[charIndexPosition++] = buffer[i];
	}
	str_money[charIndexPosition] = '\0'; // �� ���� ���� �߰�
	return str_money;
}
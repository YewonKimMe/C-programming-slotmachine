#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "betting.h"

/*
	���ϸ�: betting.c
	����: ���� money�� ���ڷ� �ް� ����� ���� �Է°��� �޾Ƽ� money���� ���� bettingMoney�� ��ȯ�ϴ� �Լ�
	����: Function
*/
int betting(int* money) {
	int bettingMoney = 0; // ���� �ݾ�
	bool betting_flag = true;
	while (true)
	{
		printf("������ �ݾ��� 1���� ������ �Է��ϼ���: ");
		scanf("%d", &bettingMoney);
		if (bettingMoney <= *money && bettingMoney > 0) { // ���� �Ӵϰ� ���� �ݾ׺��� �۰�, 0���� Ŭ ���
			if (bettingMoney % 10000 > 0) {
				printf("1���� �����θ� �����Ͻ� �� �ֽ��ϴ�. �ٽ� ������ �ּ���.\n\n");
				while (getchar() != '\n'); // �Է� ���� ����
			}
			else {
				*money -= bettingMoney;
				return bettingMoney;
			}
		}
		else {
			printf("���� �ݾ��� �ʰ��߰ų�, �ùٸ��� ���� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n");
			while (getchar() != '\n'); // �Է� ���� ����
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "betting.h"

int betting(int* money) {
	int bettingMoney = 0;
	bool betting_flag = true;
	while (true)
	{
		printf("������ �ݾ��� �Է��ϼ���: ");
		scanf("%d", &bettingMoney);
		if (bettingMoney <= *money && bettingMoney > 0) {
			*money -= bettingMoney;
			return bettingMoney;
		}
		else {
			printf("�ùٸ��� ���� ���ñݾ� �Դϴ�. �ٽ� �Է��� �ּ���.\n");
		}
	}
}
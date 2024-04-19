#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "betting.h"

int betting(int* money) {
	int bettingMoney = 0;
	bool betting_flag = true;
	while (true)
	{
		printf("배팅할 금액을 입력하세요: ");
		scanf("%d", &bettingMoney);
		if (bettingMoney <= *money && bettingMoney > 0) {
			*money -= bettingMoney;
			return bettingMoney;
		}
		else {
			printf("올바르지 않은 배팅금액 입니다. 다시 입력해 주세요.\n");
		}
	}
}
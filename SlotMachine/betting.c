#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "betting.h"

/*
	파일명: betting.c
	설명: 정수 money를 인자로 받고 사용자 정수 입력값을 받아서 money에서 빼고 bettingMoney를 반환하는 함수
	종류: Function
*/
int betting(int* money) {
	int bettingMoney = 0; // 배팅 금액
	bool betting_flag = true;
	while (true)
	{
		printf("배팅할 금액을 입력하세요: ");
		scanf("%d", &bettingMoney);
		if (bettingMoney <= *money && bettingMoney > 0) { // 배팅 머니가 보유 금액보다 작고, 0보다 클 경우
			*money -= bettingMoney; 
			return bettingMoney;
		}
		else {
			printf("올바르지 않은 배팅금액 입니다. 다시 입력해 주세요.\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
		}
	}
}
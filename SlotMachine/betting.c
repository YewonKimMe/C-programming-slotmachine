#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "betting.h"
#include "moneyUnitConvertor.h"

/*
	파일명: betting.c
	설명: 정수 money를 인자로 받고 사용자 정수 입력값을 받아서 money에서 빼고 bettingMoney를 반환하는 함수
	종류: Function
	수정일: 2024-04-20
	작성자: 김예원
*/
int betting(int* money) { // 변수 주소값을 parameter 로 가짐
	int bettingMoney = 0; // 배팅 금액
	bool betting_flag = true;
	while (true)
	{
		printf("배팅할 금액을 1만원 단위로 입력하세요: ");
		scanf("%d", &bettingMoney);
		if (bettingMoney <= *money && bettingMoney > 0) { // 배팅 머니가 보유 금액보다 작고, 0보다 클 경우, *는 역참조 연산자
			if (bettingMoney % 10000 > 0) {
				printf("1만원 단위로만 배팅하실 수 있습니다. 다시 배팅해 주세요.\n\n");
				while (getchar() != '\n'); // 입력 버퍼 비우기
			}
			else {
				*money -= bettingMoney; // 역참조 연산자로 변수에 접근해서 값 변경
				return bettingMoney;
			}
		}
		else {
			char* currentMoney = moneyUnitConvertor(money);
			printf("보유 금액 %s 원을 초과했거나, 올바르지 않은 값을 입력하셨습니다. 다시 입력해 주세요.\n", currentMoney);
			free(currentMoney);
			while (getchar() != '\n'); // 입력 버퍼 비우기
		}
	}
}
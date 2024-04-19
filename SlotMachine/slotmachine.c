#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define MAX_PATTERN 7
#define START_MONEY 1000000

int main(void)
{
    // 천 단위로 콤마를 붙이도록 로케일 설정

    int money = START_MONEY;
    int betMoney = betting(&money);

    printf("배팅금액은 %d 원 입니다.\n", betMoney);
    printf("배팅 후 잔액은 %d 원 입니다.\n", money);
    return 0;
}
/*
추상화 기능분류

1. 배팅 함수

2. 확률 검증 함수

2. 추첨 함수

3. 결과 검증 함수
*/
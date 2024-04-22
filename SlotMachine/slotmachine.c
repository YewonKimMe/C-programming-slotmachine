#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "betting.h"
#include "moneyUnitConvertor.h"

#define MAX_PATTERN 7
#define START_MONEY 10000000

int main(void)
{
    int money = START_MONEY;
    const char* convertedMoeny1 = moneyUnitConvertor(&money);
    printf("초기 보유 금액은 %s 원 입니다.\n", convertedMoeny1);
    free(convertedMoeny1);

    int betMoney = betting(&money);
    const char* convertedMoeny3 = moneyUnitConvertor(&betMoney);
    printf("배팅 금액은 %s 원 입니다.\n", convertedMoeny3);
    free(convertedMoeny3);

    char* convertedMoeny2 = moneyUnitConvertor(&money);
    printf("배팅 후 잔액은 %s 원 입니다.\n", convertedMoeny2);
    free(convertedMoeny2);
    return 0;
}
/*
    추상화 기능분류

    1. 배팅 함수

    2. 확률 검증 함수

    2. 추첨 함수

    3. 결과 검증 함수
*/
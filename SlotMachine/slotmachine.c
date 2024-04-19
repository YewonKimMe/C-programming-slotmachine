#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "betting.h"
#include "moneyUnitConvertor.h"

#define MAX_PATTERN 7
#define START_MONEY 1000000

int main(void)
{

    int money = START_MONEY;
    const char* convertedMoeny1 = moneyUnitConvertor(&money);
    printf("�ʱ� ���� �ݾ��� %s �� �Դϴ�.\n", convertedMoeny1);
    free(convertedMoeny1);

    int betMoney = betting(&money);
    const char* convertedMoeny3 = moneyUnitConvertor(&betMoney);
    printf("���� �ݾ��� %s �� �Դϴ�.\n", convertedMoeny3);
    free(convertedMoeny3);

    char* convertedMoeny2 = moneyUnitConvertor(&money);
    printf("���� �� �ܾ��� %s �� �Դϴ�.\n", convertedMoeny2);
    free(convertedMoeny2);
    return 0;
}
/*
�߻�ȭ ��ɺз�

1. ���� �Լ�

2. Ȯ�� ���� �Լ�

2. ��÷ �Լ�

3. ��� ���� �Լ�
*/
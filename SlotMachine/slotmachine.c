#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define MAX_PATTERN 7
#define START_MONEY 1000000

int main(void)
{
    // õ ������ �޸��� ���̵��� ������ ����

    int money = START_MONEY;
    int betMoney = betting(&money);

    printf("���ñݾ��� %d �� �Դϴ�.\n", betMoney);
    printf("���� �� �ܾ��� %d �� �Դϴ�.\n", money);
    return 0;
}
/*
�߻�ȭ ��ɺз�

1. ���� �Լ�

2. Ȯ�� ���� �Լ�

2. ��÷ �Լ�

3. ��� ���� �Լ�
*/
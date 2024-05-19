#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int get_accumulated_reward(const char* file_name) {
    int accumulated_money = 0;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", file_name);
        exit(1);
    }

    if (fscanf(fp, "%d", &accumulated_money) != 1) {
        fprintf(stderr, "���� %s���� ������ ���� �� �����ϴ�.\n", file_name);
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return accumulated_money;
}
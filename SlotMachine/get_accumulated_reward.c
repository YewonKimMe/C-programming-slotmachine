#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
    파일명:	get_accumulated_reward.c
    설명:	텍스트 파일에서 누적 상금 변수를 읽어와서 반환하는 함수
    종류:	Function
    수정일: 2024-05-19
*/
int get_accumulated_reward(const char* file_name) {

    int accumulated_money = 0;

    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        fprintf(stderr, "파일 %s를 열 수 없습니다.\nSlotMachine/SlotMachine 디렉토리 내에 accm_reward.txt 파일이 존재하는지 확인해 주세요.\n", file_name);
        exit(1);
    }

    if (fscanf(fp, "%d", &accumulated_money) != 1) {
        fprintf(stderr, "파일 %s에서 정수(누적금액) 를 읽을 수 없습니다.\nSlotMachine/SlotMachine 디렉토리 내에 accm_reward.txt의 첫번째 줄에 정수가 존재하는지 확인해 주세요.\n", file_name);
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return accumulated_money;
}
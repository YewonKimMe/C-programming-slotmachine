#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
	파일명:	change_accumulated_reward.c
	설명:	누적 금액을 변경하는 함수, 기존 파일을 삭제하고 갱신된 누적금액을 다시 작성하여 파일을 생성하는 함수
	종류:	Function
	수정일: 2024-05-19
*/
int change_accumulated_reward(int exist_acc_money, int use_money, char* file_name)
{
	int new_accumulated_reward = exist_acc_money + use_money;
	FILE* fp = NULL;

	if (remove(file_name) == -1)
		printf("%s 를 삭제할 수 없습니다.\n", file_name);

	fp = fopen(file_name, "a");

	// 새로운 누적 금액 작성
	fprintf(fp, "%d\n", new_accumulated_reward);

	fclose(fp);

	return new_accumulated_reward; // 새로운 누적 금액 return;
	
	
}
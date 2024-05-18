#define _CRT_SECURE_NO_WARNINGS
#define ZERO 0
#define FIVE 5
#define CLEAR 3
#include <stdio.h>


int get_selection(int input[3])
{
	int flag = 1;
	
	while (flag) {
		int cnt = 0;
		printf("0~5 사이의 배팅할 숫자 3개를 공백을 두고 입력하세요: ");
		int result = scanf("%d %d %d", &input[0], &input[1], &input[2]);
		if (result != 3) {
			printf("입력값이 잘못되었습니다. 3개의 정수를 입력해야 합니다.\n");
			while (getchar() != '\n');
			continue;
		}
		for (int i = 0; i < 3; i++) {
			if (input[i] >= ZERO && input[i] <= FIVE)
				cnt += 1;
			else
				printf("%d번째 입력값이 잘못 입력되었습니다.\n", i+1);
		}
		if (cnt == CLEAR)
			return 1;
		else {
			printf("입력 범위는 0~5 사이의 정수입니다. 입력값을 확인하고 다시 입력해주세요.\n");
			while (getchar() != '\n');
		}
		
	}
	return -1;
}
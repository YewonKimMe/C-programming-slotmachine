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
		printf("0~5 ������ ������ ���� 3���� ������ �ΰ� �Է��ϼ���: ");
		int result = scanf("%d %d %d", &input[0], &input[1], &input[2]);
		if (result != 3) {
			printf("�Է°��� �߸��Ǿ����ϴ�. 3���� ������ �Է��ؾ� �մϴ�.\n");
			while (getchar() != '\n');
			continue;
		}
		for (int i = 0; i < 3; i++) {
			if (input[i] >= ZERO && input[i] <= FIVE)
				cnt += 1;
			else
				printf("%d��° �Է°��� �߸� �ԷµǾ����ϴ�.\n", i+1);
		}
		if (cnt == CLEAR)
			return 1;
		else {
			printf("�Է� ������ 0~5 ������ �����Դϴ�. �Է°��� Ȯ���ϰ� �ٽ� �Է����ּ���.\n");
			while (getchar() != '\n');
		}
		
	}
	return -1;
}
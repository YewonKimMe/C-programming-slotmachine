#define _CRT_SECURE_NO_WARNINGS
#define ZERO 0
#define FIVE 5
#define CLEAR 3
#include <stdio.h>


int get_selection(int input[3])
{
	int flag = 1;
	int cnt = 0;
	while (flag) {
		printf("0~5 ������ ������ ���� 3���� ������ �ΰ� �Է��ϼ���: ");
		scanf("%d %d %d", &input[0], &input[1], &input[2]);

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
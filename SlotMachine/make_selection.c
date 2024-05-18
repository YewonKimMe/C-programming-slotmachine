#define _CRT_SECURE_NO_WARNINGS
#define CODE_JACKPOT 0
#define CODE_THREE_MATCH 1
#define CODE_TWO_MATCH 2
#define CODE_ONE_MATCH 3
#define CODE_NO_MATCH 4

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// �迭�� ����� ������ �����ϰ� �����ϴ� �Լ�
void array_shuffle(int arr[], int n) {

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
    ���ϸ�:	make_selection.c
    ����: ��� code��, ���� ���� �Է°� �迭��, ������� �迭�� �Է¹޾� ����ڵ忡 ���� �迭�� ����� �Լ�
    ����: Function
        @Param	: proability(double), money(int*)
        @Return	: int
    ������: 2024-05-01
*/
int make_selection(int code, int user_selected[3], int to_be_made[3])
{
    if (code == CODE_JACKPOT) { // ������ ���
        for (int i = 0; i < 3; i++) {
            to_be_made[i] = 7; // to_be_made�� ��� ��Ҹ� 7�� �����Ѵ�
        }
    }
    else if (code == CODE_THREE_MATCH) { // 3���� ��ġ�� ���
        for (int i = 0; i < 3; i++) {
            to_be_made[i] = user_selected[i]; // ������ �Է��� ���� to_be_made�� �״�� �����Ѵ�
        }
    }
    else { // �������� ��� �� TODO �����ʿ�
        int count = (code == CODE_TWO_MATCH) ? 2 : 1; // 2���� ��ġ�ߴ��� Ȯ���ϰ� ��ġ�� ��� Ƚ���� 2�� ����, �ƴ� ��� Ƚ���� 1�� ����
        int indices[3] = { 0, 1, 2 }; // ������� �迭�� �ε��� ��ȣ
        int remain = 3 - count;
        array_shuffle(indices, 3); // ������� �迭�� �ε��� ��ȣ�� �����ϰ� ���´�

        for (int i = 0; i < count; i++) {
            to_be_made[indices[i]] = user_selected[indices[i]]; // ��ġ�� ���� ��ŭ ������� �迭�� ������ �Է��� �迭[i]�� ��ġ�� ���� count��ŭ ������ ��ġindices[i]�� �����Ѵ�.
        }

        //TODO ���� �ʿ�

        for (int i = count; i < 3; i++) {
            int random_value;
            do {
                random_value = rand() % 6;
            } while (random_value == user_selected[indices[i]]);
            to_be_made[indices[i]] = random_value;
        }
    }

    if (code == CODE_NO_MATCH) {
        for (int i = 0; i < 3; i++) {
            int random_value;
            do {
                random_value = rand() % 6;
            } while (random_value == user_selected[i]);
            to_be_made[i] = random_value;
        }
    }

    return 1;
}
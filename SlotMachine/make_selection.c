#define _CRT_SECURE_NO_WARNINGS
#define CODE_JACKPOT 0
#define CODE_THREE_MATCH 1
#define CODE_TWO_MATCH 2
#define CODE_ONE_MATCH 3
#define CODE_NO_MATCH 4

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// 배열의 요소의 순서를 랜덤하게 변경하는 함수
void array_shuffle(int arr[], int n) {

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
    파일명:	make_selection.c
    설명: 결과 code와, 유저 배팅 입력값 배열과, 만들어질 배열을 입력받아 결과코드에 따른 배열을 만드는 함수
    종류: Function
        @Param	: proability(double), money(int*)
        @Return	: int
    수정일: 2024-05-01
*/
int make_selection(int code, int user_selected[3], int to_be_made[3])
{
    if (code == CODE_JACKPOT) { // 잭팟일 경우
        for (int i = 0; i < 3; i++) {
            to_be_made[i] = 7; // to_be_made의 모든 요소를 7로 세팅한다
        }
    }
    else if (code == CODE_THREE_MATCH) { // 3개가 일치할 경우
        for (int i = 0; i < 3; i++) {
            to_be_made[i] = user_selected[i]; // 유저가 입력한 값을 to_be_made에 그대로 복사한다
        }
    }
    else { // 나머지의 경우 중 TODO 수정필요
        int count = (code == CODE_TWO_MATCH) ? 2 : 1; // 2개가 일치했는지 확인하고 일치한 경우 횟수를 2로 세팅, 아닌 경우 횟수를 1로 세팅
        int indices[3] = { 0, 1, 2 }; // 만들어질 배열의 인덱스 번호
        int remain = 3 - count;
        array_shuffle(indices, 3); // 만들어질 배열의 인덱스 번호를 랜덤하게 섞는다

        for (int i = 0; i < count; i++) {
            to_be_made[indices[i]] = user_selected[indices[i]]; // 일치한 갯수 만큼 만들어질 배열에 유저가 입력한 배열[i]를 일치한 갯수 count만큼 랜덤한 위치indices[i]에 복사한다.
        }

        //TODO 수정 필요

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
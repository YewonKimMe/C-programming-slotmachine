#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "betting.h"
#include "convert_money.h"
#include "get_start_mode.h"
#include "get_random_value.h"
#include "handle_random_event.h"
#include "percentage_test.h"
#include "convert_test.h"

#define MAX_PATTERN 7
#define START_MONEY 10000000
#define JACKPOT_MULTIPLE 20

int main(void)
{   
    int game_flag = 1;
    int money = START_MONEY;

    while (game_flag)
    {
        if (!(money > 0)) {
            printf("[알림] 게임 머니를 모두 소진하여 게임을 종료합니다.\n");
            break;
        }
        int game_mode = get_start_mode(); // 사용자로부터 게임 시작 모드 획득
        if (game_mode == START_GAME) // 게임 시작
        {
            printf("------------------------------------------------\n\n");
            printf("슬롯머신 게임을 시작합니다.\n");
            const char* convertedMoeny1 = convert_money(&money);
            printf("초기 보유 금액은 %s 원 입니다.\n", convertedMoeny1);
            free(convertedMoeny1);

            int betMoney = betting(&money);
            const char* convertedMoeny3 = convert_money(&betMoney);
            printf("배팅 금액은 %s 원 입니다.\n", convertedMoeny3);
            free(convertedMoeny3);

            char* convertedMoeny2 = convert_money(&money);
            printf("배팅 후 잔액은 %s 원 입니다.\n", convertedMoeny2);
            free(convertedMoeny2);

            
            double probability = get_random_value(); // 추첨
            int k = handle_random_event(probability, &money, betMoney);

        }
        else if (game_mode == END_GAME) // 게임 종료
        {
            printf("사용자의 요청에 따라 게임을 종료합니다.\n");
            return 0;
        }
        else // 테스트 모드_개발자용
        {
            printf("테스트 모드로 진입합니다..\n");
            // 단위 테스트
            printf("======================================================================================\n");
            convert_test();
            printf("======================================================================================\n");
            // 확률 테스트
            percentage_test();
            printf("======================================================================================\n");
            break;
        }

    }

    return 0;
}
/*
    추상화 기능분류

    1. 배팅 함수

    2. 확률 검증 함수

    2. 추첨 함수

    3. 결과 검증 함수
*/
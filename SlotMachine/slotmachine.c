#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[38;5;117m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "betting.h"
#include "convert_money.h"
#include "get_start_mode.h"
#include "get_random_value.h"
#include "check_boundary.h"
#include "handle_random_event.h"
#include "get_selection.h"
#include "make_selection.h"
#include "print_selection_raffle_result.h"
#include "percentage_test.h"
#include "convert_test.h"
#include "boundary_test.h"
#include "make_selection_test.h"

#define MAX_PATTERN 7
#define START_MONEY 10000000
#define JACKPOT_MULTIPLE 20

const char* green = GREEN;
const char* red = RED;
const char* blue = BLUE;
const char* yellow = YELLOW;
const char* orange = ORANGE;
const char* reset = RESET;

int main(void)
{   
    int game_flag = 1;
    int money = START_MONEY;
    int user_bat[3] = { 0, 0, 0 }; // 유저가 배팅한 결과를 담는 배열
    int prob_random_selected[3] = { 0,0,0 }; // 추첨 결과로 생성될 결과 배열

    while (game_flag)
    {
        if (!(money > 0)) {
            printf("[알림] 게임 머니를 모두 소진하여 게임을 종료합니다.\n");
            break;
        }
        int game_mode = get_start_mode(); // 사용자로부터 게임 시작 모드 획득
        if (game_mode == START_GAME) // 게임 시작
        {
            printf("===========================================================================================================================\n");
            printf("슬롯머신 게임을 시작합니다.\n");
            printf("사용자는 %s0%s ~ %s5%s 사이의 %s숫자 3개%s를 배팅할 수 있으며, %s배팅한 숫자와 추첨 숫자 및 순서가 일치할 경우%s 일치 판정을 획득합니다.\nㄴ예시) 사용자 입력: %s3 5%s 4, 추첨 결과: %s3 5%s 1 -> 2개 일치\n\n"
            , green, reset, green, reset, blue, reset, yellow, reset, yellow, reset, yellow, reset);
            
            printf("당첨 구조는 잭팟, 3개 일치, 2개 일치, 1개 일치, 0개 일치로 구성되어 있습니다.\n잭팟은 사용자 입력값과 무관하게 추첨 숫자가 모두 7일 경우이며, 배팅 금액의 20배를 획득합니다.\n숫자 3개가 일치할 경우 배팅 금액의 10배를 획득합니다.\n숫자 2개가 일치할 경우 배팅금액의 3배를 획득합니다.\n숫자 1개가 일치할 경우 배팅금액을 다시 돌려받습니다.\n\n");
            const char* convertedMoeny1 = convert_money(&money);
            printf("초기 보유 금액은 %s%s%s 원 입니다.\n", green, convertedMoeny1, reset);
            free(convertedMoeny1);

            int betMoney = betting(&money);
            const char* convertedMoeny3 = convert_money(&betMoney);
            printf("배팅 금액은 %s%s%s 원 입니다.\n", red, convertedMoeny3, reset);
            free(convertedMoeny3);

            char* convertedMoeny2 = convert_money(&money);
            printf("배팅 후 잔액은 %s%s%s 원 입니다.\n", blue, convertedMoeny2, reset);
            free(convertedMoeny2);

            // 사용자가 0~5에서 3개의 숫자를 선택
            int result = get_selection(user_bat);
            if (result == 1)
                printf("배팅한 숫자는 %s[%d, %d, %d]%s 입니다.\n", GREEN, user_bat[0], user_bat[1], user_bat[2], RESET);
            
            double probability = get_random_value(); // 추첨

            int prob_code = check_boundary(probability);
            make_selection(prob_code, user_bat, prob_random_selected);
            // TODO 사용자 배팅 숫자와 추첨 숫자로 랜덤 결과를 출력하는 함수 추가
            int k = handle_random_event(probability, prob_code, &money, betMoney);

            print_selection_raffle_result(user_bat, prob_random_selected); // 유저 배팅 숫자와 추첨된 숫자를 출력
            
            char* convertedMoeny4 = convert_money(&money);
            printf("현재 잔액은 %s%s%s 원 입니다.\n", green, convertedMoeny4, reset);
            free(convertedMoeny4);

        }
        else if (game_mode == END_GAME) // 게임 종료
        {
            // TODO 게임결과 저장 함수 추가
            printf("사용자의 요청에 따라 게임을 종료합니다.\n");
            return 0;
        }
        else // 테스트 모드_개발자용
        {
            printf("테스트 모드로 진입합니다..\n");
            // unit 테스트
            printf("===========================================================================================================================\n");
            convert_test();
            printf("===========================================================================================================================\n");
            boundary_test();
            printf("===========================================================================================================================\n");

            // 확률 테스트
            percentage_test();
            printf("===========================================================================================================================\n");

            // 추첨 숫자 일치 테스트
            make_selection_test();
            printf("===========================================================================================================================\n");
            break;
        }

    }

    return 0;
}
/*
    추상화 기능분류

    1. 배팅 함수

    2. 확률 검증 함수

    3. 추첨 함수

    4. 결과 검증 함수

    5. 게임 결과 파일 저장 함수
*/
#define _CRT_SECURE_NO_WARNINGS
#define START_GAME 1
#define END_GAME 0
#define TEST_MODE 9
#define START_MONEY 10000000
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[38;5;117m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"
#define FILE_NAME "accm_reward.txt"


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
#include "get_accumulated_reward.h"
#include "change_accumulated_reward.h"
#include "percentage_test.h"
#include "convert_test.h"
#include "boundary_test.h"
#include "make_selection_test.h"

// CLI 출력 색상 코드
const char* green = GREEN;
const char* red = RED;
const char* blue = BLUE;
const char* yellow = YELLOW;
const char* orange = ORANGE;
const char* reset = RESET;

/*
    change_reward_procedure: 종료 시 텍스트 파일에 누적금액을 업데이트 하는 함수
*/
void change_reward_procedure(int acc_money, int use_money, const char* file_name) {
    int new_acc_reward = change_accumulated_reward(acc_money, use_money, file_name); // 누적 상금을 업데이트

    const char* converted_acc_money = convert_money(&acc_money); // 기존 누적 상금을 포멧에 맞추어 변환

    const char* converted_new_acc_reward = convert_money(&new_acc_reward); // 새로운 누적 상금을 포멧에 맞추어 변환
    if (new_acc_reward != acc_money)
        printf("%s[ >> ★ 누적 JACKPOT 상금이 갱신되었습니다. %s 원 => %s 원 ★ << ]%s\n", yellow, converted_acc_money, converted_new_acc_reward, reset);
    if (acc_money == 0)
        printf("[Notice]\tJACKPOT 당첨금 지급으로 인해 누적 상금이 %d 으로 초기화 되었습니다.\n", new_acc_reward);
}
/*
    print_acc_money: 누적 상금을 출력하는 함수
*/
void print_acc_money(char* converted_acc_money)
{
    printf("%s★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n★\t\t\t\t\t\t★\n★\t누적 JACKPOT 상금: %s 원\t★\n★\t\t\t\t\t\t★\n★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n%s", yellow, converted_acc_money, reset);
}

int main(void)
{   
    int game_flag = 1;
    int money = START_MONEY; // 유저가 현재 보유한 게임머니
    int user_bat[3] = { 0, 0, 0 }; // 유저가 배팅한 숫자 결과 3개를 담는 배열
    int prob_random_selected[3] = { 0,0,0 }; // 추첨 결과로 생성될 결과 배열
    int use_money = 0; // 유저가 배팅한 금액 중 잃은 금액이 누적되는 변수
    int acc_money = get_accumulated_reward(FILE_NAME);// 게임 시작 전 기존 누적 상금을 txt파일에서 읽어옴
    const char* converted_acc_money = convert_money(&acc_money); // 기존 누적 상금, 숫자 콤마 붙이기

    printf("%s■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■\t\t\t\t\t\t■\n■\t슬롯머신 게임에 오신 것을 환영합니다\t■\n■\t\t\t\t\t\t■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n%s", yellow, reset);
    print_acc_money(converted_acc_money);

    while (game_flag)
    {
        if (!(money > 0)) { // 잔여 보유금액이 0보다 작은 경우
            printf("%s[알림] 게임 머니를 모두 소진하여 게임을 종료합니다.%s\n", red, reset);
            change_reward_procedure(acc_money, use_money, FILE_NAME); // 누적상금을 txt 파일에 업데이트
            break;
        }
        int game_mode = get_start_mode(); // 사용자로부터 게임 시작 모드 획득
        if (game_mode == START_GAME) // 게임 시작
        {
            printf("===========================================================================================================================\n");
            printf("===========================================================================================================================\n");
            printf("===========================================================================================================================\n\n");
            printf("슬롯머신 게임을 시작합니다.\n");
            print_acc_money(converted_acc_money); // 누적 상금 출력
     
            printf("사용자는 %s0%s ~ %s5%s 사이의 %s숫자 3개%s를 배팅할 수 있으며, %s배팅한 숫자와 추첨 숫자 및 순서가 일치할 경우%s 일치 판정을 획득합니다.\n예시) 사용자 입력: %s3 5%s 4, 추첨 결과: %s3 5%s 1 -> 2개 일치\n\n"
            , green, reset, green, reset, blue, reset, yellow, reset, yellow, reset, yellow, reset);
            
            printf("당첨 구조는 잭팟, 3개 일치, 2개 일치, 1개 일치, 0개 일치로 구성되어 있습니다.\n잭팟은 사용자 입력값과 무관하게 추첨 숫자가 모두 7일 경우이며, 배팅 금액의 20배+누적상금 전체를 획득합니다.\n숫자 3개가 일치할 경우 배팅금액의 10배를 획득합니다.\n숫자 2개가 일치할 경우 배팅금액의 3배를 획득합니다.\n숫자 1개가 일치할 경우 배팅금액을 다시 돌려받습니다.\n\n");
            const char* convertedMoeny1 = convert_money(&money); // 숫자 콤마 붙이기
            printf("초기 보유 금액은 %s%s%s 원 입니다.\n", green, convertedMoeny1, reset);
            free(convertedMoeny1);

            // 배팅, 보유금액에서 차감하는 로직
            int betMoney = betting(&money);
            const char* convertedMoeny3 = convert_money(&betMoney); // 숫자 콤마 붙이기
            printf("배팅 금액은 %s%s%s 원 입니다.\n", red, convertedMoeny3, reset);
            free(convertedMoeny3);

            char* convertedMoeny2 = convert_money(&money); // 숫자 콤마 붙이기
            printf("배팅 후 잔액은 %s%s%s 원 입니다.\n", blue, convertedMoeny2, reset);
            free(convertedMoeny2);

            // 사용자가 0~5에서 3개의 숫자를 선택
            int result = get_selection(user_bat);
            if (result == 1) // 정상적으로 0~5사이의 숫자 3개를 선택한 경우
                printf("배팅한 숫자는 %s[%d, %d, %d]%s 입니다.\n", GREEN, user_bat[0], user_bat[1], user_bat[2], RESET);
            
            // 실수 확률변수 probability 랜덤하게 획득
            double probability = get_random_value();

            // 실수 확률변수를 구간값 판별을 통해 확률 결과 코드를 획득
            // 0: 잭팟, 1: 3개 일치, 2: 2개 일치, 3: 1개 일치, 4: 0개 일치
            int prob_code = check_boundary(probability);

            if (prob_code == 4) { // 하나도 맞추지 못했을 경우, 배팅금액을 사용한 금액에 누적
                use_money += betMoney; 
            }

            // 확률 결과 코드 prob_code 에 따라 유저가 배팅한 숫자 user_bat[3] 배열을 참고해서 prob_random_selected[3] 배열을 생성, 추첨 숫자 세팅
            make_selection(prob_code, user_bat, prob_random_selected);

            // prob_code에 따라 잭팟, 당첨 및 상금 지급 판정, check는 정상 수행되었다면 0
            int check = handle_random_event(probability, prob_code, &money, betMoney, &acc_money);

            // 유저 배팅 숫자와 추첨된 숫자를 출력
            print_selection_raffle_result(user_bat, prob_random_selected);
            
            char* convertedMoeny4 = convert_money(&money);

            printf("현재 잔액은 %s%s%s 원 입니다.\n", green, convertedMoeny4, reset);
            free(convertedMoeny4);
#ifdef DEBUG
            printf("use_money = %d\n", use_money);
#endif // DEBUG
        }
        else if (game_mode == END_GAME) // 게임 종료 선택
        {
            change_reward_procedure(acc_money, use_money, FILE_NAME); // 누적 상금을 txt 파일에 업데이트
            printf("사용자의 요청에 따라 게임을 종료합니다.\n");
            return 0;
        }
        else // 테스트 모드_개발자용
        {
            printf("테스트 모드로 진입합니다..\n");
            // 1. unit 테스트
            printf("===========================================================================================================================\n");
                // 숫자 천단위 콤마 붙여서 문자열로 반환하는 변환 로직 테스트
            convert_test();
            printf("===========================================================================================================================\n");
                // 실수 확률변수 x에 따라 경계값 판정 코드 prob_code 가 정상적으로 도출되는지 판단하는 테스트
            boundary_test();
            printf("===========================================================================================================================\n");
                // 추첨 숫자 생성 및 확률 판정 코드 별 일치 테스트
            make_selection_test();
            printf("===========================================================================================================================\n");

            // 2. 확률 테스트
                // n번 시행 동안 각 선택지가 얼마나 나오는지 비율로 측정, 사전에 설정한 확률과 근사하는지 확인
            percentage_test();
            printf("===========================================================================================================================\n");
            
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

    5. 누적 상금 저장 함수
*/
// 경상국립대학교 송유찬, 김예원 _ C프로그래밍 004
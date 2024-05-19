#ifndef PRINT_TEST_MESSAGE_H

#define PRINT_TEST_MESSAGE_H

void print_test_message(char* message);

void print_test_message_num(char* message, int num);

void print_test_message_str(char* message, char* str);

void print_test_result_message(char* message);

void print_percent_test_result(char* message, int cnt, int attempt_cnt, double percentage);

void print_test_success_message(char* message);

void print_test_fail_message(char* message, double value);

void print_test_fail_message_default(char* message);

void print_test_time(double used_time);

#endif
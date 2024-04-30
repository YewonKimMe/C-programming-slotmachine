#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY_JACKPOT 0.001
#define BOUNDARY_THREE_MATCH 0.01
#define BOUNDARY_TWO_MATCH 0.05
#define BOUNDARY_ONE_MATCH 0.2
#define CODE_JACKPOT 0
#define CODE_THREE_MATCH 1
#define CODE_TWO_MATCH 2
#define CODE_ONE_MATCH 3
#define CODE_NO_MATCH 4

#include <stdio.h>
#include "check_boundary.h"

int boundary_check(double probability)
{
	if (0 < probability && probability < BOUNDARY_JACKPOT) { // 0 < x < jackpot
		return CODE_JACKPOT;
	}
	else if (BOUNDARY_JACKPOT <= probability && probability < BOUNDARY_THREE_MATCH) { // jackpot <= x < three_match
		return CODE_THREE_MATCH;
	}
	else if (BOUNDARY_THREE_MATCH <= probability && probability < BOUNDARY_TWO_MATCH) {
		return CODE_TWO_MATCH;
	}
	else if (BOUNDARY_TWO_MATCH <= probability && probability < BOUNDARY_ONE_MATCH) {
		return CODE_ONE_MATCH;
	}
	else {
		return CODE_NO_MATCH;
	}
}
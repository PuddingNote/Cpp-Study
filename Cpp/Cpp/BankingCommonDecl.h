/*
업데이트 정보 : [2024-08-12] ver0.7
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LENGTH = 20;

// 프로그램 사용자의 선택 메뉴
enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌 종류
enum { NORMAL = 1, CREDIT };

#endif
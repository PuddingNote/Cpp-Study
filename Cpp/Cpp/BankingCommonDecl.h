/*
������Ʈ ���� : [2024-08-12] ver0.7
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LENGTH = 20;

// ���α׷� ������� ���� �޴�
enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

// �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// ���� ����
enum { NORMAL = 1, CREDIT };

#endif
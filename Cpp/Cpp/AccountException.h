/*
업데이트 정보 : [2024-08-16] ver0.11
*/

#include <iostream>
using namespace std;

#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

class MinusException
{
private:
	int exval;		// 예외의 원인이 되는 금액

public:
	MinusException(int val) : exval(val) {}
	void ShowExceptionInfo() const
	{
		cout << "입(출)금액 " << exval << "은 유효하지 않습니다!" << endl;
	}
};

class InsuffException
{
private:
	int balance;		// 현재 잔액
	int reqval;			// 출금 요구액

public:
	InsuffException(int val, int req) : balance(val), reqval(req) {}
	void ShowExceptionInfo() const
	{
		cout << "잔액에서 " << reqval - balance << "가(이) 부족합니다!" << endl;
	}
};

#endif
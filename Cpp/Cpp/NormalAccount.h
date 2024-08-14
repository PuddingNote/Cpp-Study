/*
업데이트 정보 : [2024-08-14] ver0.9
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
	int interRate;

public:
	//NormalAccount(int id, const char* name, int balance, int rate) : Account(id, name, balance), interRate(rate) {}
	NormalAccount(int id, String name, int balance, int rate) : Account(id, name, balance), interRate(rate) {}

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};

#endif
/*
업데이트 정보 : [2024-08-21] ver1.0
*/

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account
{
private:
	int interRate;

public:
	NormalAccount(int id, String name, int money, int rate) : Account(id, name, money), interRate(rate) {}

	virtual void Deposit(int money)
	{
		if (money < 0)
		{
			throw MinusException(money);
		}
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};

#endif
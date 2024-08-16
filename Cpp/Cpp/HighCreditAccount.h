/*
업데이트 정보 : [2024-08-16] ver0.11
*/

#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;

public:
	HighCreditAccount(int id, String name, int balance, int rate, int special) : NormalAccount(id, name, balance, rate), specialRate(special) {}
	virtual void Deposit(int money)
	{
		if (money < 0)
		{
			throw MinusException(money);
		}
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};

#endif
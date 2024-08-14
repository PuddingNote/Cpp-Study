/*
업데이트 정보 : [2024-08-14] ver0.9
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
	//HighCreditAccount(int id, const char* name, int balance, int rate, int special) : NormalAccount(id, name, balance, rate), specialRate(special) {}
	HighCreditAccount(int id, String name, int balance, int rate, int special) : NormalAccount(id, name, balance, rate), specialRate(special) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};

#endif
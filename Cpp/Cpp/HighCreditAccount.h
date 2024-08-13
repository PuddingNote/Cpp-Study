#ifndef __HIGHCREDITACCOUNT_H__
/*
업데이트 정보 : [2024-08-12] ver0.7
*/

#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount	// 신용신뢰계좌
{
private:
	int specialRate;	// 추가 이자율

public:
	HighCreditAccount(int id, const char* name, int balance, int rate, int special) : NormalAccount(id, name, balance, rate), specialRate(special) {}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};

#endif
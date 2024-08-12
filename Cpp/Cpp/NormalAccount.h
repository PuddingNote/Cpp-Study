#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account			// ���뿹�ݰ���
{
private:
	int interRate;	// ������

public:
	NormalAccount(int id, const char* name, int balance, int rate) : Account(id, name, balance), interRate(rate) {}

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};

#endif
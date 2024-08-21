/*
업데이트 정보 : [2024-08-21] ver1.0
*/

#include "String.h"

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID;
	String cusName;
	int balance;

public:
	Account(int id, String name, int money);
	int GetID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};

#endif
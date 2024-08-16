/*
업데이트 정보 : [2024-08-14] ver0.9
*/

#include "String.h"

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int id;
	String name;
	int balance;

public:
	Account(int id, String name, int balance);
	int GetID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};

#endif
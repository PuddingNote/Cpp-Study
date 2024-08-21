/*
업데이트 정보 : [2024-08-21] ver1.0
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int id, String name, int money) : accID(id), balance(money)
{
	cusName = name;
}

int Account::GetID() const
{
	return accID;
}

void Account::Deposit(int money)
{
	if (money < 0)
	{
		throw MinusException(money);
	}

	balance += money;
}

int Account::Withdraw(int money)
{
	if (money < 0)
	{
		throw MinusException(money);
	}

	if (balance < money)
	{
		throw InsuffException(balance, money);
	}

	balance -= money;

	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}
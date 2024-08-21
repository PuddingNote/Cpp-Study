/*
������Ʈ ���� : [2024-08-21] ver1.0
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
	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}
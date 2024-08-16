/*
업데이트 정보 : [2024-08-16] ver0.11
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int id, String name, int balance) : id(id), balance(balance)
{
	this->name = name;
}

int Account::GetID() const
{
	return id;
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
	cout << "출금 완료" << endl << endl;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << id << endl;
	cout << "이 름: " << name << endl;
	cout << "잔 액: " << balance << endl;
}
/*
������Ʈ ���� : [2024-08-16] ver0.11
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
	cout << "��� �Ϸ�" << endl << endl;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << id << endl;
	cout << "�� ��: " << name << endl;
	cout << "�� ��: " << balance << endl;
}
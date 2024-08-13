/*
업데이트 정보 : [2024-08-13] ver0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, const char* name, int balance) : id(id), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& copy) : id(copy.id), balance(copy.balance)
{
	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);
}

Account& Account::operator=(const Account& ref)	// ver0.8 add
{
	id = ref.id;
	balance = ref.balance;

	delete[] name;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
	return *this;
}

int Account::GetID() const
{
	return id;
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
	{
		cout << "잔액 부족" << endl << endl;
		return 0;
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

Account::~Account()
{
	delete[] name;
}
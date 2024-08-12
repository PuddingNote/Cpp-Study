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
		cout << "ÀÜ¾× ºÎÁ·" << endl << endl;
		return 0;
	}
	balance -= money;
	cout << "Ãâ±Ý ¿Ï·á" << endl << endl;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << id << endl;
	cout << "ÀÌ ¸§: " << name << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}

Account::~Account()
{
	delete[] name;
}
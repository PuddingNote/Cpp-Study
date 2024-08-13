/*
업데이트 정보 : [2024-08-13] ver0.8
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int id;
	char* name;
	int balance;

public:
	Account(int id, const char* name, int balance);
	Account(const Account& copy);
	Account& operator=(const Account& ref);		// ver0.8 add

	int GetID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif
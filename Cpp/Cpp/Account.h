#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int id;			// °èÁÂ¹øÈ£
	char* name;		// °í°´ÀÌ¸§
	int balance;	// °èÁÂÀÜ¾×

public:
	Account(int id, const char* name, int balance);
	Account(const Account& copy);

	int GetID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif
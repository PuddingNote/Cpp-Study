#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int id;			// ���¹�ȣ
	char* name;		// ���̸�
	int balance;	// �����ܾ�

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
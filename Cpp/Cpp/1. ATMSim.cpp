#include <iostream>
#include <cstring>
using namespace std;

class DepositException
{
private:
	int reqDep;		// ��û �Աݾ�

public:
	DepositException(int money) : reqDep(money)
	{

	}
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
	}
};

class WithdrawException
{
private:
	int balance;		// �ܰ�

public:
	WithdrawException(int money) : balance(money)
	{

	}
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���]" << endl;
	}
};

class Account
{
private:
	char accNum[50];	// ���¹�ȣ
	int balance;		// �ܰ�

public:
	Account(const char* acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (DepositException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (WithdrawException)
	{
		if (money > balance)
		{
			throw WithdrawException(balance);
		}
		balance -= money;
	}
	void ShowMoney()
	{
		cout << "�ܰ�: " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("123-456", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (DepositException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMoney();

	return 0;
}
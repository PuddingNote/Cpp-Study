#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LENGTH	20
#define MAX_CLIENT	100

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

class Account
{
private:
	int id;			// 계좌번호
	char* name;		// 고객이름
	int balance;	// 계좌잔액

public:
	Account(int id, const char* name, int balance) : id(id), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Account(const Account& copy) : id(copy.id), balance(copy.balance)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(this->name, copy.name);
	}
	int GetID() const
	{
		return id;
	}
	void Deposit(int money)
	{
		balance += money;
	}
	int Withdraw(int money)
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
	void ShowAccInfo() const
	{
		cout << "계좌ID: " << id << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << balance << endl;
	}
	~Account()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

class AccountHandler
{
private:
	Account* account[MAX_CLIENT];
	int accountNum;

public:
	AccountHandler() : accountNum(0)
	{

	}
	void ShowMenu() const		// 메뉴 출력
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}
	void MakeAccount()			// 계좌 개설
	{
		int id;
		char name[NAME_LENGTH];
		int money;

		cout << "[계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;
		cout << endl;

		account[accountNum++] = new Account(id, name, money);

		cout << "개설 완료" << endl << endl;
	}
	void DepositMoney()			// 입금
	{
		int id;
		int money;

		cout << "[입     금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "입금액: ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accountNum; i++)
		{
			if (account[i]->GetID() == id)
			{
				account[i]->Deposit(money);
				cout << "입금 완료" << endl << endl;;
				return;
			}
		}

		cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
	}
	void WithdrawMoney()		// 출금
	{
		int id;
		int money;

		cout << "[출     금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "출금액: ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accountNum; i++)
		{
			if (account[i]->GetID() == id)
			{
				account[i]->Withdraw(money);
				return;
			}
		}

		cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
	}
	void ShowAccInfo() const	// 잔액 조회
	{
		for (int i = 0; i < accountNum; i++)
		{
			cout << "-----" << i + 1 << "번 고객-----" << endl;
			account[i]->ShowAccInfo();
			cout << endl;
		}
	}
	~AccountHandler()
	{
		for (int i = 0; i < accountNum; i++)
		{
			delete account[i];
		}
	}
};

int main(void)
{
	AccountHandler manager;
	int input;

	while (true)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> input;
		cout << endl;

		switch (input)
		{
		case CREATE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case SHOW:
			manager.ShowAccInfo();
			break;
		case EXIT:
			cout << "프로그램 종료" << endl;
			return 0;
		default:
			cout << "잘못된 선택" << endl << endl;
		}
	}

	return 0;
}
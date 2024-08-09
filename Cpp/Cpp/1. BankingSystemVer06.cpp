#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LENGTH	20
#define MAX_CLIENT	100

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT };

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
		delete[] name;
	}
};

class NormalAccount : public Account			// 보통예금계좌
{
private:
	int interRate;	// 이자율

public:
	NormalAccount(int id, const char* name, int balance, int rate) : Account(id, name, balance), interRate(rate)
	{

	}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};

class HighCreditAccount : public NormalAccount	// 신용신뢰계좌
{
private:
	int specialRate;	// 추가 이자율

public:
	HighCreditAccount(int id, const char* name, int balance, int rate, int special) : NormalAccount(id, name, balance, rate), specialRate(special)
	{

	}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
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
	void MakeAccount()
	{
		int input;

		cout << "[계좌종류선택]" << endl;
		cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
		cin >> input;

		switch (input)
		{
		case NORMAL:
			MakeNormalAccount();
			break;
		case CREDIT:
			MakeCreditAccount();
			break;
		}
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

protected:
	void MakeNormalAccount()
	{
		int id;
		char name[NAME_LENGTH];
		int money;
		int interRate;

		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이  름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;
		cout << "이자율: ";
		cin >> interRate;
		cout << endl;

		account[accountNum++] = new NormalAccount(id, name, money, interRate);

		cout << "보통예금계좌 개설완료" << endl << endl;
	}
	void MakeCreditAccount()
	{
		int id;
		char name[NAME_LENGTH];
		int money;
		int interRate;
		int creditLevel;

		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이  름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;
		cout << "이자율: ";
		cin >> interRate;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> creditLevel;
		cout << endl;

		switch (creditLevel)
		{
		case 1:
			account[accountNum++] = new HighCreditAccount(id, name, money, interRate, LEVEL_A);
			break;
		case 2:
			account[accountNum++] = new HighCreditAccount(id, name, money, interRate, LEVEL_B);
			break;
		case 3:
			account[accountNum++] = new HighCreditAccount(id, name, money, interRate, LEVEL_C);
			break;
		}

		cout << "신용신뢰계좌 개설완료" << endl << endl;
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
			break;
		}
	}

	return 0;
}
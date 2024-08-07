#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LENGTH	20
#define MAX_CLIENT	100

void MainMenu();	// 메뉴 출력
void Create();		// 계좌 개설
void Deposit();		// 입금
void Withdraw();	// 출금
void Show();		// 잔액 조회

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

class Client
{
private:
	int id;			// 계좌번호
	char* name;		// 고객이름
	int balance;	// 계좌잔액

public:
	Client(int id, const char* name, int balance) : id(id), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Client(const Client& copy) : id(copy.id), balance(copy.balance)
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
	void Show() const
	{
		cout << "계좌ID: " << id << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << balance << endl;
	}
	~Client()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

Client* client[MAX_CLIENT];
int clientNum = 0;

int main(void)
{
	int input;

	while (true)
	{
		MainMenu();
		cout << "선택: ";
		cin >> input;
		cout << endl;

		switch (input)
		{
		case CREATE:
			Create();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case SHOW:
			Show();
			break;
		case EXIT:
			for (int i = 0; i < clientNum; i++)
			{
				delete client[i];
			}
			cout << "프로그램 종료" << endl;
			return 0;
		default:
			cout << "잘못된 번호" << endl << endl;
		}
	}

	return 0;
}

void MainMenu()
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void Create()
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

	client[clientNum++] = new Client(id, name, money);

	cout << "개설 완료" << endl << endl;
}

void Deposit()
{
	int id;
	int money;

	cout << "[입     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i]->GetID() == id)
		{
			client[i]->Deposit(money);
			cout << "입금 완료" << endl << endl;;
			return;
		}
	}

	cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
}

void Withdraw()
{
	int id;
	int money;

	cout << "[출     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i]->GetID() == id)
		{
			client[i]->Withdraw(money);
			return;
		}
	}

	cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
}

void Show()
{
	for (int i = 0; i < clientNum; i++)
	{
		cout << "-----" << i + 1 << "번 고객-----" << endl;
		client[i]->Show();
		cout << endl;
	}
}
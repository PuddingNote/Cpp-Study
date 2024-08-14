#include <iostream>
using namespace std;

#define NAME_LENGTH 20
#define MAX_CLIENT 100

void MainMenu();	// 메뉴 출력
void Create();		// 계좌 개설
void Deposit();		// 입금
void Withdraw();	// 출금
void Show();		// 잔액 조회

typedef struct
{
	int id;
	char name[NAME_LENGTH];
	int balance;
} Client;

Client client[MAX_CLIENT];
int clientNum = 0;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

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
	int price;

	cout << "[계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> price;
	cout << endl;

	client[clientNum].id = id;
	strcpy_s(client[clientNum].name, name);
	client[clientNum].balance = price;

	clientNum++;

	cout << "개설 완료" << endl << endl;
}

void Deposit()
{
	int id;
	int price;

	cout << "[입     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> price;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i].id == id)
		{
			client[i].balance += price;

			cout << "입금 완료" << endl << endl;;
			return;
		}
	}

	cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
}

void Withdraw()
{
	int id;
	int price;

	cout << "[출     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> price;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i].id == id)
		{
			if (price > client[i].balance)
			{
				cout << "잔액 부족" << endl << endl;
				return;
			}

			client[i].balance -= price;

			cout << "출금 완료" << endl << endl;
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
		cout << "계좌ID: " << client[i].id << endl;
		cout << "이 름: " << client[i].name << endl;
		cout << "잔 액: " << client[i].balance << endl;
		cout << endl;
	}
}
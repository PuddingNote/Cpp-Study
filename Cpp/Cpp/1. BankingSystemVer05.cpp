#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LENGTH	20
#define MAX_CLIENT	100

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

class Account
{
private:
	int id;			// ���¹�ȣ
	char* name;		// ���̸�
	int balance;	// �����ܾ�

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
			cout << "�ܾ� ����" << endl << endl;
			return 0;
		}
		balance -= money;
		cout << "��� �Ϸ�" << endl << endl;
		return money;
	}
	void ShowAccInfo() const
	{
		cout << "����ID: " << id << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << balance << endl;
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
	void ShowMenu() const		// �޴� ���
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
	}
	void MakeAccount()			// ���� ����
	{
		int id;
		char name[NAME_LENGTH];
		int money;

		cout << "[���� ����]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> money;
		cout << endl;

		account[accountNum++] = new Account(id, name, money);

		cout << "���� �Ϸ�" << endl << endl;
	}
	void DepositMoney()			// �Ա�
	{
		int id;
		int money;

		cout << "[��     ��]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "�Աݾ�: ";
		cin >> money;
		cout << endl;

		for (int i = 0; i < accountNum; i++)
		{
			if (account[i]->GetID() == id)
			{
				account[i]->Deposit(money);
				cout << "�Ա� �Ϸ�" << endl << endl;;
				return;
			}
		}

		cout << "��ġ�ϴ� ID�� ���� ���� ����" << endl << endl;
	}
	void WithdrawMoney()		// ���
	{
		int id;
		int money;

		cout << "[��     ��]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "��ݾ�: ";
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

		cout << "��ġ�ϴ� ID�� ���� ���� ����" << endl << endl;
	}
	void ShowAccInfo() const	// �ܾ� ��ȸ
	{
		for (int i = 0; i < accountNum; i++)
		{
			cout << "-----" << i + 1 << "�� ��-----" << endl;
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
		cout << "����: ";
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
			cout << "���α׷� ����" << endl;
			return 0;
		default:
			cout << "�߸��� ����" << endl << endl;
		}
	}

	return 0;
}
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
		delete[] name;
	}
};

class NormalAccount : public Account			// ���뿹�ݰ���
{
private:
	int interRate;	// ������

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

class HighCreditAccount : public NormalAccount	// �ſ�ŷڰ���
{
private:
	int specialRate;	// �߰� ������

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
	void ShowMenu() const		// �޴� ���
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
	}
	void MakeAccount()
	{
		int input;

		cout << "[������������]" << endl;
		cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
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

protected:
	void MakeNormalAccount()
	{
		int id;
		char name[NAME_LENGTH];
		int money;
		int interRate;

		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "��  ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> money;
		cout << "������: ";
		cin >> interRate;
		cout << endl;

		account[accountNum++] = new NormalAccount(id, name, money, interRate);

		cout << "���뿹�ݰ��� �����Ϸ�" << endl << endl;
	}
	void MakeCreditAccount()
	{
		int id;
		char name[NAME_LENGTH];
		int money;
		int interRate;
		int creditLevel;

		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "��  ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> money;
		cout << "������: ";
		cin >> interRate;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
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

		cout << "�ſ�ŷڰ��� �����Ϸ�" << endl << endl;
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
			break;
		}
	}

	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LENGTH	20
#define MAX_CLIENT	100

void MainMenu();	// �޴� ���
void Create();		// ���� ����
void Deposit();		// �Ա�
void Withdraw();	// ���
void Show();		// �ܾ� ��ȸ

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

class Client
{
private:
	int id;			// ���¹�ȣ
	char* name;		// ���̸�
	int balance;	// �����ܾ�

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
			cout << "�ܾ� ����" << endl << endl;
			return 0;
		}
		balance -= money;
		cout << "��� �Ϸ�" << endl << endl;
		return money;
	}
	void Show() const
	{
		cout << "����ID: " << id << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << balance << endl;
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
		cout << "����: ";
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
			cout << "���α׷� ����" << endl;
			return 0;
		default:
			cout << "�߸��� ��ȣ" << endl << endl;
		}
	}

	return 0;
}

void MainMenu()
{
	cout << "-----Menu------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void Create()
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

	client[clientNum++] = new Client(id, name, money);

	cout << "���� �Ϸ�" << endl << endl;
}

void Deposit()
{
	int id;
	int money;

	cout << "[��     ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i]->GetID() == id)
		{
			client[i]->Deposit(money);
			cout << "�Ա� �Ϸ�" << endl << endl;;
			return;
		}
	}

	cout << "��ġ�ϴ� ID�� ���� ���� ����" << endl << endl;
}

void Withdraw()
{
	int id;
	int money;

	cout << "[��     ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
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

	cout << "��ġ�ϴ� ID�� ���� ���� ����" << endl << endl;
}

void Show()
{
	for (int i = 0; i < clientNum; i++)
	{
		cout << "-----" << i + 1 << "�� ��-----" << endl;
		client[i]->Show();
		cout << endl;
	}
}
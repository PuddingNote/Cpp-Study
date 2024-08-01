#include <iostream>
using namespace std;

#define NAME_LENGTH 20
#define MAX_CLIENT 100

void MainMenu();	// �޴� ���
void Create();		// ���� ����
void Deposit();		// �Ա�
void Withdraw();	// ���
void Show();		// �ܾ� ��ȸ

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
	int price;

	cout << "[���� ����]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> price;
	cout << endl;

	client[clientNum].id = id;
	strcpy_s(client[clientNum].name, name);
	client[clientNum].balance = price;

	clientNum++;

	cout << "���� �Ϸ�" << endl << endl;
}

void Deposit()
{
	int id;
	int price;

	cout << "[��     ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> price;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i].id == id)
		{
			client[i].balance += price;

			cout << "�Ա� �Ϸ�" << endl << endl;;
			return;
		}
	}

	cout << "��ġ�ϴ� ID�� ���� ���� ����" << endl << endl;
}

void Withdraw()
{
	int id;
	int price;

	cout << "[��     ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> price;
	cout << endl;

	for (int i = 0; i < clientNum; i++)
	{
		if (client[i].id == id)
		{
			if (price > client[i].balance)
			{
				cout << "�ܾ� ����" << endl << endl;
				return;
			}

			client[i].balance -= price;

			cout << "��� �Ϸ�" << endl << endl;
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
		cout << "����ID: " << client[i].id << endl;
		cout << "�� ��: " << client[i].name << endl;
		cout << "�� ��: " << client[i].balance << endl;
		cout << endl;
	}
}
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"

AccountHandler::AccountHandler() : accountNum(0)
{

}

void AccountHandler::ShowMenu() const		// �޴� ���
{
	cout << "-----Menu------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount()
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

void AccountHandler::MakeNormalAccount()
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

void AccountHandler::MakeCreditAccount()
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

void AccountHandler::DepositMoney()			// �Ա�
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

void AccountHandler::WithdrawMoney()		// ���
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

void AccountHandler::ShowAccInfo() const	// �ܾ� ��ȸ
{
	for (int i = 0; i < accountNum; i++)
	{
		cout << "-----" << i + 1 << "�� ��-----" << endl;
		account[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountNum; i++)
	{
		//delete account[i];	// ���⼭ �� ������ �ߴ��� �𸣰���
	}
}
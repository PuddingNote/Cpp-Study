/*
������Ʈ ���� : [2024-08-21] ver1.0
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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
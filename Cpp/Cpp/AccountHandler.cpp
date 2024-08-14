/*
업데이트 정보 : [2024-08-14] ver0.9
*/

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "String.h"

AccountHandler::AccountHandler() : accountNum(0)
{

}

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
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

void AccountHandler::MakeNormalAccount()
{
	int id;
	//char name[NAME_LENGTH];
	String name;
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

void AccountHandler::MakeCreditAccount()
{
	int id;
	//char name[NAME_LENGTH];
	String name;
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

void AccountHandler::DepositMoney()
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

void AccountHandler::WithdrawMoney()
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

void AccountHandler::ShowAccInfo() const
{
	for (int i = 0; i < accountNum; i++)
	{
		cout << "-----" << i + 1 << "번 고객-----" << endl;
		account[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountNum; i++)
	{
		// 여기서 왜 오류가 뜨는지 모르겠음
		// 여러개의 포인터가 하나의 주소를 가리켜서 여러번 삭제될때 동일한 오류가 떴었음
		//delete account[i];
	}
}
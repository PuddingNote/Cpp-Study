/*
업데이트 정보 : [2024-08-21] ver1.0
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
	cout << "선택 : ";
	cin >> input;
	
	if (input == NORMAL)
	{
		MakeNormalAccount();
	}
	else if (input == CREDIT)
	{
		MakeCreditAccount();
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
	}
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	String name;
	int money;
	int interRate;

	cout << "[보통예금계좌 개설 시작]" << endl;
	while (true)
	{
		bool flag = false;

		cout << "계좌ID: ";
		cin >> id;

		for (int i = 0; i < accountNum; i++)
		{
			if (id == account[i]->GetID())
			{
				flag = true;
				cout << "이미 일치하는 ID가 있습니다. 다시 입력해 주세요" << endl;
				break;
			}
		}

		if (flag == false) break;
	}
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
	String name;
	int money;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설 시작]" << endl;
	while (true)
	{
		bool flag = false;

		cout << "계좌ID: ";
		cin >> id;

		for (int i = 0; i < accountNum; i++)
		{
			if (id == account[i]->GetID())
			{
				flag = true;
				cout << "이미 일치하는 ID가 있습니다. 다시 입력해 주세요" << endl;
				break;
			}
		}

		if (flag == false) break;
	}
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
		cout << "신용신뢰계좌 개설완료" << endl << endl;
		return;
	case 2:
		account[accountNum++] = new HighCreditAccount(id, name, money, interRate, LEVEL_B);
		cout << "신용신뢰계좌 개설완료" << endl << endl;
		return;
	case 3:
		account[accountNum++] = new HighCreditAccount(id, name, money, interRate, LEVEL_C);
		cout << "신용신뢰계좌 개설완료" << endl << endl;
		return;
	}

	cout << "잘못된 입력입니다." << endl;
	cout << "신용신뢰계좌 개설 실패" << endl;
}

void AccountHandler::DepositMoney()
{
	int id;
	int money;

	cout << "[입     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	while (true)
	{
		cout << "입금액: ";
		cin >> money;
		cout << endl;

		try
		{
			for (int i = 0; i < accountNum; i++)
			{
				if (id == account[i]->GetID())
				{
					account[i]->Deposit(money);
					cout << "입금 완료" << endl << endl;
					return;
				}
			}
			cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "입금액만 재입력하세요." << endl;
		}
	}
}

void AccountHandler::WithdrawMoney()
{
	int id;
	int money;

	cout << "[출     금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	while (true)
	{
		cout << "출금액: ";
		cin >> money;
		cout << endl;

		try
		{
			for (int i = 0; i < accountNum; i++)
			{
				if (id == account[i]->GetID())
				{
					account[i]->Withdraw(money);
					cout << "출금 완료" << endl << endl;
					return;
				}
			}
			cout << "일치하는 ID가 존재 하지 않음" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "입금액만 재입력하세요." << endl;
		}
		catch (InsuffException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "출금액만 재입력하세요." << endl;
		}
	}
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
	// 오류 분석 필요 : Account.h의 Deposit함수를 가상함수로 처리 안했었음;
	for (int i = 0; i < accountNum; i++)
	{
		//cout << account[i] << endl;
		delete account[i];
	}
}
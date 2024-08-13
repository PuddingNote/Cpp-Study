/*
업데이트 정보 : [2024-08-13] ver0.8
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	//Account* account[100];
	BoundCheckAccountPtrArray account;	// ver0.8
	int accountNum;

public:
	AccountHandler();

	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAccInfo() const;
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

#endif
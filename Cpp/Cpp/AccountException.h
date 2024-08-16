/*
������Ʈ ���� : [2024-08-16] ver0.11
*/

#include <iostream>
using namespace std;

#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

class MinusException
{
private:
	int exval;		// ������ ������ �Ǵ� �ݾ�

public:
	MinusException(int val) : exval(val) {}
	void ShowExceptionInfo() const
	{
		cout << "��(��)�ݾ� " << exval << "�� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class InsuffException
{
private:
	int balance;		// ���� �ܾ�
	int reqval;			// ��� �䱸��

public:
	InsuffException(int val, int req) : balance(val), reqval(req) {}
	void ShowExceptionInfo() const
	{
		cout << "�ܾ׿��� " << reqval - balance << "��(��) �����մϴ�!" << endl;
	}
};

#endif
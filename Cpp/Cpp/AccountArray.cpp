/*
업데이트 정보 : [2024-08-13] ver0.8
*/

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int index)
{
	if (index < 0 || index >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int index) const
{
	if (index < 0 || index >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[] arr;
}
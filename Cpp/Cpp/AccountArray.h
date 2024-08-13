/*
업데이트 정보 : [2024-08-13] ver0.8
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {}

public:
	BoundCheckAccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int index);
	ACCOUNT_PTR operator[](int index) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};

#endif
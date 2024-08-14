#ifndef __ARRAY_TEMPLATE_
#define __ARRAY_TEMPLATE_

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len);
	T& operator[](int index);
	T operator[](int index) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template <class T>
T& BoundCheckArray<T>::operator[](int index)
{
	if (index < 0 || index >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

template <class T>
T BoundCheckArray<T>::operator[](int index) const
{
	if (index < 0 || index >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

template <class T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}

#endif
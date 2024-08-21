/*
업데이트 정보 : [2024-08-21] ver1.0
*/

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

template <class T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len = 100);
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
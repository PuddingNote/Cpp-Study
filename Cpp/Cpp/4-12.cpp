// 클래스 템플릿 Array
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Array
{
	T* buf;
	int size;
	int capacity;

public:
	explicit Array(int cap = 100) :buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}
	~Array()
	{
		delete[] buf;
	}
	void Add(T data)
	{
		buf[size++] = data;
	}
	T operator[](int index) const
	{
		return buf[index];
	}
	int GetSize() const
	{
		return size;
	}
};

int main()
{
	Array<int> iarr;
	iarr.Add(10);
	iarr.Add(20);
	iarr.Add(30);

	for (int i = 0; i < iarr.GetSize(); i++)
	{
		cout << iarr[i] << " ";
	}
	cout << endl;

	Array<double> darr;
	darr.Add(10.12);
	darr.Add(20.12);
	darr.Add(30.12);

	for (int i = 0; i < darr.GetSize(); i++)
	{
		cout << darr[i] << " ";
	}
	cout << endl;

	Array<string> sarr;
	sarr.Add("abc");
	sarr.Add("ABC");
	sarr.Add("Hello!");

	for (int i = 0; i < sarr.GetSize(); i++)
	{
		cout << sarr[i] << " ";
	}
	cout << endl;

	return 0;
}
// ObjectInfo Ư��ȭ ����
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class ObjectInfo
{
	T data;
public:
	ObjectInfo(const T& d) : data(d) { }

	void Print()
	{
		cout << "Ÿ�� : " << typeid(data).name() << endl;
		cout << "ũ�� : " << sizeof(data) << endl;
		cout << "�� : " << data << endl << endl;
	}
};

template <>
class ObjectInfo<string>
{
	string data;
public:
	ObjectInfo(const string& d) : data(d) { }

	void Print()
	{
		cout << "Ÿ�� : " << "string" << endl;
		cout << "���ڿ� ���� : " << sizeof(data) << endl;
		cout << "�� : " << data << endl << endl;
	}
};

int main()
{
	ObjectInfo<int> d1(10);
	d1.Print();

	ObjectInfo<double> d2(5.5);
	d2.Print();

	ObjectInfo<string> d3("Hello!");
	d3.Print();

	return 0;
}
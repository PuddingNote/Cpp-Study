// ObjectInfo 특수화 버전
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
		cout << "타입 : " << typeid(data).name() << endl;
		cout << "크기 : " << sizeof(data) << endl;
		cout << "값 : " << data << endl << endl;
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
		cout << "타입 : " << "string" << endl;
		cout << "문자열 길이 : " << sizeof(data) << endl;
		cout << "값 : " << data << endl << endl;
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
// 타입 변환 연산자 오버로딩
#include <iostream>
using namespace std;

class A
{

};

class B
{
public:
	operator A()
	{
		cout << "operator A() 호출" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int() 호출" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double() 호출" << endl;
		return 5.5;
	}
};

int main()
{
	A a;
	int n;
	double d;

	B b;

	// 암시적 호출
	a = b;
	n = b;
	d = b;
	cout << endl;

	// 명시적 호출
	a = b.operator A();
	n = b.operator int();
	d = b.operator double();

	return 0;
}
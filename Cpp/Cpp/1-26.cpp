// Ÿ�� ��ȯ ������ �����ε�
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
		cout << "operator A() ȣ��" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int() ȣ��" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double() ȣ��" << endl;
		return 5.5;
	}
};

int main()
{
	A a;
	int n;
	double d;

	B b;

	// �Ͻ��� ȣ��
	a = b;
	n = b;
	d = b;
	cout << endl;

	// ����� ȣ��
	a = b.operator A();
	n = b.operator int();
	d = b.operator double();

	return 0;
}
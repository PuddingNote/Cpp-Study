// �Լ� ���ø��� ����� Ÿ�� ���� �� ȣ��
#include <iostream>
using namespace std;

template <class T>
void Print(T a, T b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	Print<int>(10, 20);
	Print<double>(0.123, 1.123);
	Print<const char*>("ABC", "abc");

	return 0;
}
// �ΰ��� �Ű������� ���� �Լ� ���ø�
#include <iostream>
using namespace std;

template <class T1, class T2>
void Print(T1 a, T2 b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	Print(10, 1.5);
	Print("Hello", 100);
	Print(1.5, "Hello");

	return 0;
}
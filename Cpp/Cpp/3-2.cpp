// �� ������ �Ű������� ���� �Լ� ��ü
#include <iostream>
using namespace std;

void Print(int a, int b)
{
	cout << "�����Լ�: " << a << ", " << b << endl;
}

struct Functor
{
	void operator() (int a, int b)
	{
		cout << "�Լ���ü: " << a << ", " << b << endl;
	}
};

int main()
{
	Functor functor;

	Print(10, 20);
	functor(10, 20);		// functor.operator()(10,20)

	return 0;
}
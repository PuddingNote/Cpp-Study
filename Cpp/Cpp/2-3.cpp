// c++ �Լ� ȣ�� ���
#include <iostream>
using namespace std;

void Print()
{
	cout << "���� �Լ� Print()" << endl;
}

class Point
{
public:
	void Print()
	{
		cout << "��� �Լ� Print()" << endl;
	}
};

int main()
{
	Point pt;
	Point* p = &pt;

	Print();		// ���� �Լ� ȣ��
	pt.Print();		// ��ü�� ��� �Լ� ȣ��
	p->Print();		// �ּҷ� ��� �Լ� ȣ��

	return 0;
}
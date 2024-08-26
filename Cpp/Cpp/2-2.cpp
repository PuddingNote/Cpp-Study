// �Լ� ������ ����� ���
#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "����: " << n << endl;
}

int main()
{
	// void Print(int n)�� �Լ� ������ ����
	void (*pf)(int);

	// �Լ��� �̸��� �Լ��� ���� �ּ�
	pf = Print;

	Print(10);	// 1. �Լ� ȣ��
	pf(10);		// 2. �����͸� �̿��� �Լ� ȣ��, ù��° ���
	(*pf)(10);	// 3. �����͸� �̿��� �Լ� ȣ��, �ι�° ���

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;

	return 0;
}
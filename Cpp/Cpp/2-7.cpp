// �ݹ� �Լ�
#include <iostream>
using namespace std;

void Client();

// ����
void PrintHello()
{
	cout << "Hello!" << endl;
	Client();
}

// Ŭ���̾�Ʈ
void Client()
{
	cout << "�� client" << endl;
}

int main()
{
	PrintHello();

	return 0;
}
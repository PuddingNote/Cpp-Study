#include <iostream>
using namespace std;

// reinterpret_cast<T>(expt)
// �����͸� ��������ϴ�, �����Ϳ� ������ �ִ� ��� ������ �� ��ȯ�� ���
// 1
//int main(void)
//{
//	int num = 0x010203;
//	char* ptr = reinterpret_cast<char*>(&num);
//
//	for (int i = 0; i < sizeof(num); i++)
//	{
//		cout << static_cast<int>(*(ptr + i)) << endl;
//	}
//
//	return 0;
//}

// 2
int main(void)
{
	int num = 72;
	int* ptr = &num;

	int adr = reinterpret_cast<int>(ptr);	// �ּҰ��� ������ ��ȯ
	cout << "Addr: " << adr << endl;

	int* rptr = reinterpret_cast<int*>(adr);	// ������ �ٽ� �ּҰ����� ��ȯ
	cout << "value: " << rptr << endl;

	return 0;
}
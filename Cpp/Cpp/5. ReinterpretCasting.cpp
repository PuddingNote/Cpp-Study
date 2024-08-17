#include <iostream>
using namespace std;

// reinterpret_cast<T>(expt)
// 포인터를 대상으로하는, 포인터와 관련이 있는 모든 유형의 형 변환을 허용
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

	int adr = reinterpret_cast<int>(ptr);	// 주소값을 정수로 변환
	cout << "Addr: " << adr << endl;

	int* rptr = reinterpret_cast<int*>(adr);	// 정수를 다시 주소값으로 변환
	cout << "value: " << rptr << endl;

	return 0;
}
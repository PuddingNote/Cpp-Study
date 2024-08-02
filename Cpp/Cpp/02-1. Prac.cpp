// 문제 1
//#include <iostream>
//using namespace std;
//
//void PlusByRef(int& num)
//{
//	num += 1;
//}
//
//void SwapByRef(int& num)
//{
//	num *= -1;
//}
//
//
//int main(void)
//{
//	int num1 = 10;
//	int num2 = 20;
//
//	PlusByRef(num1);
//	SwapByRef(num2);
//
//	cout << "num1: " << num1 << endl;
//	cout << "num2: " << num2 << endl;
//
//	return 0;
//}

// 문제 2
// 변수 선언없이 값을 넣었기 때문에 주소를 가져와서 실행하는 SwapByRef2() 함수가 인지할 수 없다.

// 문제 3
#include <iostream>
using namespace std;

void SwapPointer(int* (&ptr1), int* (&ptr2))
{
	int* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

int main(void)
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout << "ptr1: " << ptr1 << endl;
	cout << "*ptr1: " << *ptr1 << endl << endl;
	cout << "ptr2: " << ptr2 << endl;
	cout << "*ptr2: " << *ptr2 << endl;

	return 0;
}
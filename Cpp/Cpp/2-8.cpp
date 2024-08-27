// 함수 포인터를 이용한 콜백 메커니즘 구현
#include <iostream>
using namespace std;

// 서버
void For_each(int* begin, int* end, void(*pf)(int))
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

// 클라이언트
void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << " ";
}

void Print3(int n)
{
	cout << "정수: " << n << endl;
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	For_each(arr, arr + 5, Print1);
	cout << endl << endl;
	For_each(arr, arr + 5, Print2);
	cout << endl << endl;
	For_each(arr, arr + 5, Print3);
	cout << endl << endl;

	return 0;
}
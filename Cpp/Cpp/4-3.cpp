// 함수 템플릿
#include <iostream>
using namespace std;

template <class T>
void Print(T a, T b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abc");

	return 0;
}
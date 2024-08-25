// 함수, 함수 포인터, 함수 객체를 이용한 정수 출력
#include <iostream>
using namespace std;

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "정수: " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "정수: " << arg << endl;
}

int main()
{
	void (*Print2)(int) = Print1;
	FuncObject Print3;

	Print1(10);		// 함수를 사용한 정수 출력
	Print2(10);		// 함수 포인터를 사용한 정수 출력
	Print3(10);		// 함수 객체를 사용한 정수 출력

	return 0;
}
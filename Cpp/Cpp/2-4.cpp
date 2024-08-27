// 정적 함수 포인터
#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "전역함수: " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A 전역 함수: " << n << endl;
	}
}

class Point
{
public:
	static void Print(int n)
	{
		cout << "Point 클래스의 정적 멤버 함수: "	<< n << endl;
	}
};

int main()
{
	void (*pf)(int);

	Print(10);
	A::Print(10);
	Point::Print(10);

	pf = Print;
	pf(10);
	pf = A::Print;
	pf(10);
	pf = Point::Print;
	pf(10);

	return 0;
}
// 두 정수형 매개변수를 같는 함수 객체
#include <iostream>
using namespace std;

void Print(int a, int b)
{
	cout << "전역함수: " << a << ", " << b << endl;
}

struct Functor
{
	void operator() (int a, int b)
	{
		cout << "함수객체: " << a << ", " << b << endl;
	}
};

int main()
{
	Functor functor;

	Print(10, 20);
	functor(10, 20);		// functor.operator()(10,20)

	return 0;
}
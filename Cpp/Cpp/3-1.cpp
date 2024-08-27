// 함수 객체 정의
#include <iostream>
using namespace std;

void Print()
{
	cout << "전역 함수" << endl;
}

struct Functor
{
	void operator() ()
	{
		cout << "함수 객체" << endl;
	}
};

int main()
{
	Functor functor;

	Print();		// 전역 함수 호출
	functor();		// 멤버 함수 호출 / functor.operator()

	return 0;
}
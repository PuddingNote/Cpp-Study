// 반환 타입과 매개변수 타입을 인자로 같는 함수 객체
#include <iostream>
#include <cstring>
using namespace std;

template <class RetType, class ArgType>
class Functor
{
public:
	RetType operator() (ArgType data)
	{
		cout << data << endl;
		return RetType();
	}
};

int main()
{
	Functor<void, int> functor1;
	functor1(10);

	Functor<bool, string> functor2;
	functor2("Hello");

	return 0;
}
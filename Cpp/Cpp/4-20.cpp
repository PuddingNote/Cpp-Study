// 함수 객체(PrintFunctor)를 사용한 For_each()
#include <iostream>
#include <cstring>
using namespace std;

template <class IterT, class Func>
void For_each(IterT begin, IterT end, Func pf)
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

// 정수는 디폴트 출력 구분자 " ", 문자열은 *\n사용
template <class T>
struct PrintFunctor
{
	string sep;

	explicit PrintFunctor(const string& s = " ") : sep(s) { }
	void operator()(T data) const
	{
		cout << data << sep;
	}
};

int main()
{
	int arr[5] = { 10,20,30,40,50 };
	For_each(arr, arr + 5, PrintFunctor<int>());
	cout << endl;

	string sarr[3] = { "abc", "ABC", "Hello" };
	For_each(sarr, sarr + 3, PrintFunctor<string>("*\n"));
	cout << endl;

	return 0;
}
#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	
	// 함수 템플릿의 특수화 : 아래처럼 템플릿 함수의 구성방법에 예외를 둘 필요가 있을때 사용 - 다음 예제
	cout << Max("Simple", "Best") << endl;	// 단순히 주소 값의 비교결과가 반환

	return 0;
}
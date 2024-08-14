#include <iostream>
using namespace std;

// 함수 템플릿
template <typename T>	// template <class T> 와 동일
T Add(T num1, T num2)
{
	return num1 + num2;
}

// 템플릿 함수 = 템플릿을 기반으로 컴파일러가 만들어내는 함수
//int Add<int>(int num1, int num2)
//{
//	return num1 + num2;
//}
//double Add<double>(double num1, double num2)
//{
//	return num1 + num2;
//}

int main(void)
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl << endl;

	// 전달되는 인자의 자료형을 참조하여 호출될 함수의 유형을 컴파일러가 결정 : <자료형> 안써도 사용 가능
	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;

	return 0;
}
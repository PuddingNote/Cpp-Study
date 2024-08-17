#include <iostream>
using namespace std;

void ShowString(const char* str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
	cout << n1 + n2 << endl;
}

// const_cast<T>(expt)
// const성향을 제거하는 형 변환
int main(void)
{
	const char* name = "Lee Sung Ju";
	ShowString(const_cast<char*>(name));

	const int& num1 = 100; 
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));

	return 0;
}
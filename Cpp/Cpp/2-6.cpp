// 서버 코드와 클라이언트 코드
#include <iostream>
using namespace std;

// 서버
void PrintHello()
{
	cout << "Hello!" << endl;
}

// 클라이언트
int main()
{
	PrintHello();

	return 0;
}

// 클라이언트가 서버 호출 : 콜
// 서버가 클라이언트 호출 : 콜백
// 콜백 함수
#include <iostream>
using namespace std;

void Client();

// 서버
void PrintHello()
{
	cout << "Hello!" << endl;
	Client();
}

// 클라이언트
void Client()
{
	cout << "난 client" << endl;
}

int main()
{
	PrintHello();

	return 0;
}
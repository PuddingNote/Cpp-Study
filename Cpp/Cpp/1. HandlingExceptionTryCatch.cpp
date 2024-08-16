// throw에 의해 던져진 '예외 데이터'는 그것을 감싸고 있는 try 블록에 의해 감지가 되고
// 이어서 등장하는 catch 블록에 의해 처리된다.
#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	// try 블록 내에서 예외가 발생하면, 예외가 발생한 지점 이후의 나머지 try영역은 건너뛴다.
	try
	{
		if (num2 == 0)
		{
			throw num2;
		}
		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	catch(int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요" << endl;
	}
	cout << "end of main" << endl;

	return 0;
}
#include <iostream>
using namespace std;

// 예외처리는 가급적 간결한 구조를 띠는게 좋기 때문에, 정말 필요한 상황이 아니라면
// 굳이 예외를 다시 던질 필요는 없다.
void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
		{
			throw 0;
		}
		cout << "몫: " << num1 / num2 << endl;
		cout << "나머지: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw;		// 예외를 다시 던짐
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
	}

	return 0;
}
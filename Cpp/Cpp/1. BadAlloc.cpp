#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000];

			// 원래라면 예외가 발생해야하는데 무한하게 진행되서 추가함
			if (num == 50) return 0;
		}
	}
	catch (bad_alloc& bad)
	{
		cout << bad.what() << endl;
		cout << "더 이상 할당 불가" << endl;
	}

	return 0;
}
#include <iostream>
using namespace std;

void SimpleFuncOne();
void SimpleFuncTwo();
void SimpleFuncThree();

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch(int expn)
	{
		cout << "예외코드: " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne()
{
	cout << "SimpleFuncOne()" << endl;
	SimpleFuncTwo();
}
void SimpleFuncTwo()
{
	cout << "SimpleFuncTwo()" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree()
{
	cout << "SimpleFuncThree()" << endl;
	throw(-1);
}
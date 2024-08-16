#include <iostream>
using namespace std;

class AAA
{
public:
	void ShowYou()
	{
		cout << "AAA exception!" << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception!" << endl;
	}
};

class CCC : public BBB
{
public:
	void ShowYou()
	{
		cout << "CCC exception!" << endl;
	}
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
	{
		throw AAA();
	}
	else if (expn == 2)
	{
		throw BBB();
	}
	else
	{
		throw CCC();
	}
}

int main(void)
{
	// 모든 예외 객체가 AAA클래스를 상속하기 때문에 catch 블록을
	// AAA - BBB - CCC 순서가 아닌 CCC - BBB - AAA 순서로 변경해야한다.
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (CCC& expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch(AAA& expn)
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}

	return 0;
}
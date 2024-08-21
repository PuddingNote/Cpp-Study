#include <iostream>
using namespace std;

class Number
{
private:
	int num;

public:
	Number(int n) : num(n) {}
	void ShowData()
	{
		cout << num << endl;
	}

	Number* operator->()
	{
		return this;
	}
	Number& operator*()
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;		// (num.operator*()) = 30;
	num->ShowData();	// num.operator->() -> ShowData();
	(*num).ShowData();	// (num.operator*()).ShowData();

	return 0;
}
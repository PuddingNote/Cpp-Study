// C++에서 상속은 public 상속만 있다고 생각을 해라! -> 다중상속같은 특별한 경우가 아니면 다른건 잘 사용하지 않는다.
#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{

	}
};

class Derived : protected Base
{ 

};

class DeDerived : public Derived
{

};

int main(void)
{
	Derived drv;
	cout << drv.num3 << endl;

	DeDerived ddrv;
	cout << ddrv.num3 << endl;

	return 0;
}
// 멤버 변수를 갖는 함수 객체
#include <iostream>
using namespace std;

class Adder
{
private:
	int total;

public:
	explicit Adder(int n = 0) :total(n) {}
	int operator() (int n)
	{
		return total += n;
	}
};

int main()
{
	Adder add(0);

	cout << add(10) << endl;
	cout << add(20) << endl;
	cout << add(30) << endl;

	return 0;
}
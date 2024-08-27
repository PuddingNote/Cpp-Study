#include <iostream>
using namespace std;

class Adder
{
	
public:
	//Adder() {}
	int operator()(int n1, int n2)
	{
		return n1 + n2;
	}
};

int main()
{
	Adder add;

	int sum = add(10, 20);
	cout << "sum = " << sum << endl;

	return 0;
}
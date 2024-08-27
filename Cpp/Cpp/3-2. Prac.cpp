#include <iostream>
using namespace std;

class Equal
{
	//int a;
	//int b;

public:
	//Equal() : a(0), b(0) {}
	//Equal(int n1, int n2) : a(n1), b(n2) {}
	bool operator()(int n1, int n2)
	{
		if (n1 == n2) 
			return true;
		else 
			return false;
	}
};

int main()
{
	Equal cmp;

	if (cmp(10, 20))
	{
		cout << "같다!" << endl;
	}
	else
	{
		cout << "다르다!" << endl;
	}

	return 0;
}
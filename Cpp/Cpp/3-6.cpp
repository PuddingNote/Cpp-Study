// STLÀÇ less ÇÔ¼ö °´Ã¼
#include <iostream>
#include <functional>
using namespace std;

typedef less<int> Less;

int main()
{
	Less l;

	cout << l(10, 20) << endl;
	cout << l(20, 10) << endl << endl;

	cout << l.operator()(10, 20) << endl;
	cout << l.operator()(20, 10) << endl << endl;

	cout << Less()(10, 20) << endl;
	cout << Less()(20, 10) << endl << endl;

	cout << Less().operator()(10, 20) << endl;
	cout << Less().operator()(20, 10) << endl;

	return 0;
}
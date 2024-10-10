// listÀÇ sort()
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l;

	l.push_back(20);
	l.push_back(10);
	l.push_back(50);
	l.push_back(30);
	l.push_back(40);

	list<int>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l.sort();
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
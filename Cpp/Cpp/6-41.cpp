// list의 조건자 버전 unique()
#include <iostream>
#include <list>
using namespace std;

bool Predicate(int first, int second)
{
	return second - first <= 0;
}

int main()
{
	list<int> l;

	l.push_back(10);
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(30);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	l.push_back(10);

	list<int>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l.unique(Predicate);
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
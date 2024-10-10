// list의 조건자 버전 sort()
#include <iostream>
#include <list>
using namespace std;

struct Greater
{
	bool operator () (int left, int right) const
	{
		return left > right;
	}
};

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

	l.sort(greater<int>());
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l.sort(less<int>());
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l.sort(Greater());
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
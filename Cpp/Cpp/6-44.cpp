// listÀÇ merge()
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l1;
	list<int> l2;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);

	l2.push_back(25);
	l2.push_back(35);
	l2.push_back(60);

	list<int>::iterator iter;
	cout << "l1 : ";
	for (iter = l1.begin(); iter != l1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "l2 : ";
	for (iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l1.merge(l2);

	cout << "l1 : ";
	for (iter = l1.begin(); iter != l1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "l2 : ";
	for (iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
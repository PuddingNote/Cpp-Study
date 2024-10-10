// listÀÇ splice()
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

	l2.push_back(100);
	l2.push_back(200);
	l2.push_back(300);
	l2.push_back(400);
	l2.push_back(500);

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
	cout << endl << "=================" << endl;

	iter = l1.begin();
	iter++;
	iter++;

	l1.splice(iter, l2);

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
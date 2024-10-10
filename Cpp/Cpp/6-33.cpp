// listÀÇ insert()¿Í erase()
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	list<int>::iterator iter = l.begin();
	list<int>::iterator iter2;
	iter++;
	iter++;

	iter2 = l.erase(iter);

	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "iter2 : " << *iter2 << endl;

	iter = iter2;
	iter2 = l.insert(iter, 300);

	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "iter2 : " << *iter2 << endl;

	return 0;
}
// list의 push_back, push_front, 반복자
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

	list<int>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	l.push_front(100);
	l.push_front(200);

	for (iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
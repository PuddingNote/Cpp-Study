// list의 splice() 다른 버전
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

	list<int>::iterator iter1;
	list<int>::iterator iter2;

	cout << "l1 : ";
	for (iter1 = l1.begin(); iter1 != l1.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;

	cout << "l2 : ";
	for (iter2 = l2.begin(); iter2 != l2.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl << "=================" << endl;

	// 
	iter1 = l1.begin();
	iter1++;
	iter1++;

	iter2 = l2.begin();
	iter2++;

	l1.splice(iter1, l2, iter2);


	cout << "l1 : ";
	for (iter1 = l1.begin(); iter1 != l1.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;

	cout << "l2 : ";
	for (iter2 = l2.begin(); iter2 != l2.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl << "=================" << endl;

	// 
	l1.splice(l1.end(), l2, l2.begin(), l2.end());

	cout << "l1 : ";
	for (iter1 = l1.begin(); iter1 != l1.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;

	cout << "l2 : ";
	for (iter2 = l2.begin(); iter2 != l2.end(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl;

	return 0;
}
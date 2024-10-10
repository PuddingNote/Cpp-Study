// list¿Í vectorÀÇ insert()
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> v;
	list<int> l;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	vector<int>::iterator viter = v.begin();
	viter++;
	list<int>::iterator liter = l.begin();
	liter++;

	viter = v.insert(viter, 600);
	liter = l.insert(liter, 600);

	cout << "vector : " << *viter << endl;
	cout << "list : " << *liter << endl;

	cout << "vector : ";
	for (viter = v.begin(); viter != v.end(); viter++)
	{
		cout << *viter << " ";
	}
	cout << endl;

	cout << "list : ";
	for (liter = l.begin(); liter != l.end(); liter++)
	{
		cout << *liter << " ";
	}
	cout << endl;

	return 0;
}
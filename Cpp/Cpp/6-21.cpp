// iterator¿Í reverse_iterator
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int arr[5] = { 10,20,30,40,50 };

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	vector<int>::reverse_iterator riter;

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	for (riter = v.rbegin(); riter != v.rend(); riter++)
	{
		cout << *riter << " ";
	}
	cout << endl;

	return 0;
}
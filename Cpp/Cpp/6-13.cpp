// vector의 front()와 back() 참조
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.front() = 100;
	v.back() = 500;

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
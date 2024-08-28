// vector�� ������ �ݺ���
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

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator riter(v.rbegin());
	for (; riter != v.rend(); riter++)
	{
		cout << *riter << " ";
	}
	cout << endl;

	return 0;
}
// vector�� front()�� back()
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

	cout << v[0] << ", " << v.front() << endl;	// ù��° ����
	cout << v[4] << ", " << v.back() << endl;	// ������ ����

	return 0;
}
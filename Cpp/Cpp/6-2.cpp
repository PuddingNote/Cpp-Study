// vector의 size_type
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

	// vector의 size()는 unsigned int 타입
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << typeid(vector<int>::size_type).name() << endl;

	return 0;
}
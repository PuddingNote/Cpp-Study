// 다른 버전의 insert() 멤버 함수
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

	vector<int>::iterator iter = v.begin() + 2;

	v.insert(iter, 3, 100);

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;



	vector<int> v2;

	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	iter = v2.begin() + 1;

	v2.insert(iter, v.begin(), v.end());

	for (iter = v2.begin(); iter != v2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
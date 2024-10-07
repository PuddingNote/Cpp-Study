// 일반 반복자와 상수 반복자
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

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();
	
	cout << *iter << endl;		// 가리키는 원소의 참조
	cout << *citer << endl;		// 가리키는 원소의 상수 참조
	
	cout << *++iter << endl;	// 다음 원소로 이동한 원소의 참조
	cout << *++citer << endl;	// 다음 원소로 이동한 원소의 상수 참조

	*iter = 100;			// 변경 가능
	//*citer = 100;			// 변경 불가능

	return 0;
}
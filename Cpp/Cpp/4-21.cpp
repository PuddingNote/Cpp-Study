// 템플릿 Less, Greater
#include <iostream>
#include <functional>
using namespace std;

template <class T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

template <class T>
struct Greater
{
	bool operator()(T a, T b)
	{
		return a > b;
	}
};

int main()
{
	// 사용자 Less, Greater 사용
	cout << Less<int>()(10, 20) << endl;
	cout << Greater<int>()(10, 20) << endl << endl;

	// STL 사용
	cout << less<int>()(10, 20) << endl;
	cout << greater<int>()(10, 20) << endl;

	return 0;
}
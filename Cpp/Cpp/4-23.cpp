#include <iostream>
#include <cstring>
using namespace std;

template <class T1, class T2>
struct Pair
{
	T1 first;
	T2 second;
	Pair(const T1& ft, const T2& sd) : first(ft), second(sd) { }
};

int main()
{
	// »ç¿ëÀÚ
	Pair<int, int> p1(10, 20);
	cout << p1.first << ", " << p1.second << endl;

	Pair<int, string> p2(1, "one");
	cout << p2.first << ", " << p2.second << endl << endl;

	// STL
	pair<int, int> p3(10, 20);
	cout << p3.first << ", " << p3.second << endl;

	pair<int, string> p4(1, "one");
	cout << p4.first << ", " << p4.second << endl;

	return 0;
}
// 컨테이너 기본 할당기 allocator<T>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 할당기는 특정 작업에 최적화된 메모리 할당 모델을 구축할 때 사용되지만
// 대부분 기본 할당기 만으로도 충분하다.
int main()
{
	vector<int, allocator<int>> v;
	v.push_back(10);
	cout << *v.begin() << endl;

	set<int, less<int>, allocator<int>> s;
	s.insert(10);
	cout << *s.begin() << endl;

	return 0;
}
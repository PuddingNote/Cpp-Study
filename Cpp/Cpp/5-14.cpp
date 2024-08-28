// �����̳� �⺻ �Ҵ�� allocator<T>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// �Ҵ��� Ư�� �۾��� ����ȭ�� �޸� �Ҵ� ���� ������ �� ��������
// ��κ� �⺻ �Ҵ�� �����ε� ����ϴ�.
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
// swap�� ����� �Ҵ� �޸� ����
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(5);
	cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

	// �⺻�����ڷ� ���� vector�����̳ʿ� v�����̳ʸ� swap�Ѵ�.
	vector<int>().swap(v);
	cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

	return 0;
}
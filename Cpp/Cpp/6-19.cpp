// �Ϲ� �ݺ��ڿ� ��� �ݺ���
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
	
	cout << *iter << endl;		// ����Ű�� ������ ����
	cout << *citer << endl;		// ����Ű�� ������ ��� ����
	
	cout << *++iter << endl;	// ���� ���ҷ� �̵��� ������ ����
	cout << *++citer << endl;	// ���� ���ҷ� �̵��� ������ ��� ����

	*iter = 100;			// ���� ����
	//*citer = 100;			// ���� �Ұ���

	return 0;
}
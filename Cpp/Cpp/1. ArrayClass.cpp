#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	// �迭�� ������� �����̰�, ����ҿ� ����� �����ʹ� ���ϼ��� ����޾ƾ��Ѵ�.
	// ���� ��κ��� ��� ������� ����� ���ʿ��ϰų� �߸��� �Ϸ� �����ϱ� ������
	// �������簡 �ǵ��� Ŭ������ �����ϴ°� �ƴ϶� private����� ����� ������ ��õ������ ���°� ����.
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int index)
	{
		if (index < 0 || index >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[index];
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}

	/*for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}*/

	BoundCheckIntArray cpy(5);
	cpy = arr;						// �������� ���� �ڵ�
	BoundCheckIntArray copy = arr;	// �������� ���� �ڵ�

	return 0;
}
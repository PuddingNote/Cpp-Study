// Point Ŭ������ int Ÿ�� ��ȯ ������
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	operator int() const
	{
		return xpos;
	}
};

int main()
{
	int n = 10;

	Point pt(2, 3);
	n = pt;				// pt.operator int() �Ͻ��� ȣ��
	cout << n << endl;

	return 0;
}
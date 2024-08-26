// explicit Point ������
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
};

int main()
{
	Point p;
	p.Print();

	p = 10;			// �Ͻ��� ������ ȣ�� �Ұ���
	p = Point(10);	// ����� ������ ȣ�� ����
	
	p.Print();

	return 0;
}
// ����Ʈ ������ PointPtr Ŭ���� ����
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
};

// �������� ������ Point��ü�� �ڵ����� �Ҹ��� ���� �� ���� (�Ǽ��� delete�� �ȽἭ ����� �޸� ���� ����)
class PointPtr
{
private:
	Point* ptr;

public:
	PointPtr(Point* p) : ptr(p) { }
	~PointPtr()
	{
		delete ptr;
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3);
	PointPtr p2 = new Point(5, 5);
	
	// ���� ��� ����
	p1->Print();
	p2->Print();

	delete p1;
	delete p2;

	return 0;
}
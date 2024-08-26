// *������ �����ε�
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

	Point* operator->() const
	{
		return ptr;
	}
	Point& operator*() const
	{
		return *ptr;
	}
};

int main()
{
	Point* p1 = new Point(2, 3);		// �Ϲ� ������
	PointPtr p2 = new Point(5, 5);		// ����Ʈ ������

	p1->Print();	// p1->Print()
	p2->Print();	// p2.operator->()->Print()
	cout << endl;

	(*p1).Print();	// (*p1).Print()
	(*p2).Print();	// p2.operator*().Print()

	delete p1;

	return 0;
}
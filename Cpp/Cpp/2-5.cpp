// Point Ŭ������ ��� �Լ� ������
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	void PrintInt(int n)
	{
		cout << "�׽�Ʈ ����: " << n << endl;
	}
};

int main()
{
	Point pt(2, 3);
	Point* p = &pt;

	void (Point:: * pf1) () const;		// ��� �Լ� ������ ����
	pf1 = &Point::Print;

	void (Point:: * pf2) (int);			// ��� �Լ� ������ ����
	pf2 = &Point::PrintInt;

	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	// ��ü�� ��� �Լ� �����͸� �̿��� ȣ��
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;

	// �ּҷ� ��� �Լ� �����͸� �̿��� ȣ��
	(p->*pf1)();
	(p->*pf2)(10);

	return 0;
}
//// 문제 1
//#include <iostream>
//using namespace std;
//
//class Point
//{
//private:
//	int xpos;
//	int ypos;
//
//public:
//	Point(int x, int y) : xpos(x), ypos(y)
//	{
//
//	}
//	void ShowPointInfo() const
//	{
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//};
//
//class Circle
//{
//private:
//	Point p;
//	int radius;
//
//public:
//	Circle (int x, int y, int rad) : p(x,y), radius(rad)
//	{
//		
//	}
//	void ShowCircleInfo() const
//	{
//		cout << "radius: " << radius << endl;
//		p.ShowPointInfo();
//	}
//};
//
//class Ring
//{
//private:
//	Circle innerCircle;
//	Circle outterCircle;
//
//public:
//	Ring(int x1, int y1, int rad1, int x2, int y2, int rad2) : innerCircle(x1, y1, rad1), outterCircle(x2, y2, rad2)
//	{
//		
//	}
//	void ShowRingInfo() const
//	{
//		cout << "Inner Circle Info..." << endl;
//		innerCircle.ShowCircleInfo();
//
//		cout << "Outter Circle Info..." << endl;
//		outterCircle.ShowCircleInfo();
//	}
//};
//
//int main(void)
//{
//	Ring ring(1, 1, 4, 2, 2, 9);
//	ring.ShowRingInfo();
//
//	return 0;
//}

// 문제 2
#include <iostream>
using namespace std;

namespace COMP_POS
{
	enum 
	{ 
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER 
	};

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl << endl;
			break;
		case SENIOR:
			cout << "주임" << endl << endl;
			break;
		case ASSIST:
			cout << "대리" << endl << endl;
			break;
		case MANAGER:
			cout << "과장" << endl << endl;
			break;
		}
	}
}

class NameCard
{
private:
	char* name;
	char* companyName;
	char* phone;
	int position;

public:
	NameCard(const char* n, const char* cN, const char* p, int pos)
	{
		int len = strlen(n) + 1;
		name = new char[len];
		strcpy(name, n);
		
		len = strlen(cN) + 1;
		companyName = new char[len];
		strcpy(companyName, cN);

		len = strlen(p) + 1;
		phone = new char[len];
		strcpy(phone, p);

		position = pos;
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << companyName << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		COMP_POS::ShowPositionInfo(position);
	}
	~NameCard()
	{
		delete[]name;
		delete[]companyName;
		delete[]phone;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
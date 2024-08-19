// 문제 1
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class Point
//{
//private:
//	int xpos, ypos;
//
//public:
//	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
//	friend ostream& operator<<(ostream& os, const Point& pos);
//	friend ostream& operator<<(ostream& os, const Point* pos);
//};
//
//ostream& operator<<(ostream& os, const Point& pos)
//{
//	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//	return os;
//}
//
//ostream& operator<<(ostream& os, const Point* pos)
//{
//	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
//	return os;
//}
//
//typedef Point* POINT_PTR;
//
//class BoundCheckPointArray
//{
//private:
//	POINT_PTR* arr;
//	int arrlen;
//	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
//	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
//
//public:
//	BoundCheckPointArray(int len) : arrlen(len)
//	{
//		arr = new POINT_PTR[len];
//	}
//	POINT_PTR& operator[](int index)
//	{
//		if (index < 0 || index >= arrlen)
//		{
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//		return arr[index];
//	}
//	POINT_PTR operator[] (int index) const
//	{
//		if (index < 0 || index >= arrlen)
//		{
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//		return arr[index];
//	}
//	int GetArrLen() const
//	{
//		return arrlen;
//	}
//	~BoundCheckPointArray()
//	{
//		delete[] arr;
//	}
//};
//
//int main(void)
//{
//	BoundCheckPointArray arr(3);
//	arr[0] = new Point(3, 4);
//	arr[1] = new Point(5, 6);
//	arr[2] = new Point(7, 8);
//
//	for (int i = 0; i < arr.GetArrLen(); i++)
//	{
//		cout << arr[i];
//	}
//
//	delete arr[0];
//	delete arr[1];
//	delete arr[2];
//
//	return 0;
//}

// 문제 2
// 2차원배열 연산자 오버로딩
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
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
	int operator[] (int index) const
	{
		if (index < 0 || index >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[index];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray** arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}

public:
	BoundCheck2DIntArray(int col, int row) : arrlen(col)
	{
		arr = new BoundCheckIntArrayPtr[col];
		for (int i = 0; i < col; i++)
		{
			arr[i] = new BoundCheckIntArray(row);
		}
	}
	BoundCheckIntArray& operator[](int index)
	{
		if (index < 0 || index >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[index]);
	}
	~BoundCheck2DIntArray()
	{
		for (int i = 0; i < arrlen; i++)
		{
			delete arr[i];
		}
		delete[] arr;
	}

	ostream& operator[](ostream& os)
	{

		return os;
	}
};

int main(void)
{
	BoundCheck2DIntArray arr2d(3, 4);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr2d[i][j] = i + j;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr2d[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
// 문제 1
//#include <iostream>
//using namespace std;
//
//class Rectangle	// 직사각형
//{
//private:
//	int width;
//	int height;
//
//public:
//	Rectangle(int w, int h) : width(w), height(h)
//	{
//
//	}
//	void ShowAreaInfo()
//	{
//		cout << "면적: " << width * height << endl;
//	}
//};
//
//class Square : public Rectangle	// 정사각형
//{
//private:
//
//public:
//	Square(int length) : Rectangle(length, length)
//	{
//
//	}
//};
//
//int main(void)
//{
//	Rectangle rec(4, 3);
//	rec.ShowAreaInfo();
//
//	Square sqr(7);
//	sqr.ShowAreaInfo();
//
//	return 0;
//}

// 문제 2
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* name, const char* num, int p) : price(p)
	{
		title = new char[strlen(name) + 1];
		strcpy(title, name);

		isbn = new char[strlen(num) + 1];
		strcpy(isbn, num);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMkey;

public:
	EBook(const char* name, const char* num, int p, const char* k) : Book(name, num, p)
	{
		DRMkey = new char[strlen(k) + 1];
		strcpy(DRMkey, k);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMkey << endl;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}
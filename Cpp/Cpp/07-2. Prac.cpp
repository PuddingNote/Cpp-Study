// ���� 1
//#include <iostream>
//using namespace std;
//
//class Rectangle	// ���簢��
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
//		cout << "����: " << width * height << endl;
//	}
//};
//
//class Square : public Rectangle	// ���簢��
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

// ���� 2
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
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
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
		cout << "����Ű: " << DRMkey << endl;
	}
};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}
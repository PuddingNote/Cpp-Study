// 문제 1
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Gun
//{
//private:
//	int bullet;
//
//public:
//	Gun(int bnum) : bullet(bnum)
//	{
//
//	}
//	void Shot()
//	{
//		cout << "BBANG!" << endl;
//		bullet--;
//	}
//};
//
//class Police
//{
//private:
//	int handcuffs;
//	Gun* pistol;
//
//public:
//	Police(int bnum, int bcuff) : handcuffs(bcuff)
//	{
//		if (bnum > 0)
//		{
//			pistol = new Gun(bnum);
//		}
//		else
//		{
//			pistol = NULL;
//		}
//	}
//	Police(const Police& cpy) : handcuffs(cpy.handcuffs)
//	{
//		if (cpy.pistol > 0)
//		{
//			pistol = new Gun(*(cpy.pistol));
//		}
//		else
//		{
//			pistol = NULL;
//		}
//		
//	}
//	Police& operator=(const Police& ref)
//	{
//		if (pistol != NULL)
//		{
//			delete pistol;
//		}
//
//		if (ref.pistol != NULL)
//		{
//			pistol = new Gun(*(ref.pistol));
//		}
//		else
//		{
//			pistol = NULL;
//		}
//		handcuffs = ref.handcuffs;
//		return *this;
//	}
//	void PutHandcuff()
//	{
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//	void Shot()
//	{
//		if (pistol == NULL)
//		{
//			cout << "Hut BBANG!" << endl;
//		}
//		else
//		{
//			pistol->Shot();
//		}
//	}
//	~Police()
//	{
//		if (pistol != NULL)
//		{
//			delete pistol;
//		}
//	}
//};
//
//int main(void)
//{
//	Police pman1(5, 3);
//	Police pman2 = pman1;	// 복사 생성자 호출
//	pman2.PutHandcuff();
//	pman2.Shot();
//
//	Police pman3(2, 4);
//	pman3 = pman1;			// 대입 연산자 호출
//	pman3.PutHandcuff();
//	pman3.Shot();
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
	Book(const Book& cpy) : price(cpy.price)
	{
		title = new char[strlen(cpy.title) + 1];
		strcpy(title, cpy.title);

		isbn = new char[strlen(cpy.isbn) + 1];
		strcpy(isbn, cpy.isbn);
	}
	Book& operator=(const Book& ref)
	{
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		price = ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
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
	EBook(const EBook& cpy) : Book(cpy)
	{
		DRMkey = new char[strlen(cpy.DRMkey) + 1];
		strcpy(DRMkey, cpy.DRMkey);
	}
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMkey;

		DRMkey = new char[strlen(ref.DRMkey) + 1];
		strcpy(DRMkey, ref.DRMkey);

		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMkey << endl;
	}
	~EBook()
	{
		delete[] DRMkey;
	}
};

int main(void)
{
	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;	// 복사 생성자 호출
	ebook2.ShowEBookInfo();
	cout << endl;

	EBook ebook3("test", "test", 0, "test");
	ebook3 = ebook1;		// 대입 연산자 호출
	ebook3.ShowBookInfo();

	return 0;
}
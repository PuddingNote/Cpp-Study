#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor" << endl;
	}
	Person& operator=(const Person& ref)
	{
		delete[] name;		// 메모리의 누수를 막기 위한 메모리 해제 연산

		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}
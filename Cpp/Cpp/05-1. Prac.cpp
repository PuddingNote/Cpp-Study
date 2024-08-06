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
			cout << "���" << endl << endl;
			break;
		case SENIOR:
			cout << "����" << endl << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl << endl;
			break;
		case MANAGER:
			cout << "����" << endl << endl;
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
	NameCard(const char* name, const char* companyName, const char* phone, int pos) : position(pos)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->companyName = new char[strlen(companyName) + 1];
		strcpy(this->companyName, companyName);

		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, phone);
	}
	NameCard(const NameCard& copy) : position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

		companyName = new char[strlen(copy.companyName) + 1];
		strcpy(companyName, copy.companyName);

		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << companyName << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: ";
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
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
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}
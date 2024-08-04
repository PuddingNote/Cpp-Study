// ¹®Á¦ 1
#include <iostream>
using namespace std;

class Calculator
{
private:
	int addCount;
	int minCount;
	int mulCount;
	int divCount;
public:
	void Init();
	float Add(float num1, float num2);
	float Min(float num1, float num2);
	float Mul(float num1, float num2);
	float Div(float num1, float num2);
	void ShowOpCount();
};

void Calculator::Init()
{
	int addCount = 0;
	int minCount = 0;
	int mulCount = 0;
	int divCount = 0;
}

float Calculator::Add(float num1, float num2)
{
	addCount += 1;

	return num1 + num2;
}

float Calculator::Min(float num1, float num2)
{
	minCount += 1;

	return num1 - num2;
}

float Calculator::Mul(float num1, float num2)
{
	mulCount += 1;

	return num1 * num2;
}

float Calculator::Div(float num1, float num2)
{
	divCount += 1;

	return num1 / num2;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << addCount << " »¬¼À: " << minCount << " °ö¼À: " << mulCount << " ³ª´°¼À: " << divCount << endl;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}

// ¹®Á¦ 2
#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char str[30];	// string s;

public:
	void SetString(const char* s);	// void SetString(string s);
	void ShowString();
};

void Printer::SetString(const char* s)	// void Printer::SetString(string s)
{
	strcpy(str, s);	// this->s = s;
}

void Printer::ShowString()
{
	cout << str << endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}
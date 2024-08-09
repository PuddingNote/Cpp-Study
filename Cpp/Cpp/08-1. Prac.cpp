// 오렌지미디어 급여관리 시스템
#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
	enum
	{
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
	};
}

class Employee			// 추상 클래스 : 순수 가상함수로 선언한 클래스
{
private:
	char name[100];

public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;				// 순수 가상함수
	virtual void ShowSalaryInfo() const = 0;	// 순수 가상함수
};

class TemporaryWorker : public Employee			// 임시직
{
private:
	int workTime;
	int payPerHour;

public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{

	}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class PermanentWorker : public Employee			// 정규직
{
private:
	int salary;

public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money)
	{

	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker		// 영업직
{
private:
	int salesResult;
	double bonusRatio;

public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{

	}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	double riskLevel;

public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk) : SalesWorker(name, money, ratio), riskLevel(risk)
	{

	}
	int GetRiskPay() const
	{
		return SalesWorker::GetPay() * (riskLevel / 100);
	}
	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{

	}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤(핸들러) 클래스의 객체생성
	EmployeeHandler handler;

	// 해외 영업직 등록
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	return 0;
}
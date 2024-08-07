// �������̵�� �޿����� �ý���
// Ȯ�强 ����
#include <iostream>
using namespace std;

class PermanentWorker	// ������
{	// �������� ����
private:
	char name[100];
	int salary;	// �Ŵ� �����ؾ� �ϴ� �޿���

public:
	PermanentWorker(const char* name, int money) : salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{	// ����� ���� : ����� ó���� ������ ����ϴ� Ŭ������ ��Ʈ��(�ڵ鷯) Ŭ������� �θ���.
private:
	PermanentWorker* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{

	}
	void AddEmployee(PermanentWorker* emp)
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
	// ���������� �������� ����� ��Ʈ��(�ڵ鷯) Ŭ������ ��ü����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1000));
	handler.AddEmployee(new PermanentWorker("JUN", 1000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();

	return 0;
}
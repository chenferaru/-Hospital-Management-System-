#include "HeaderEmployee.h"
int Employee::counter = 0;

Employee::Employee(const string& EmployeeName)
{
	if (EmployeeName.empty())
		throw "Invalid name!";
	setEmployeeName(EmployeeName);
	++counter;
	m_employeeNum = counter;
}

const string& Employee::getEmployeeName() const
{
	return m_employeeName;
}

int Employee::getEmployeeNum() const
{
	return m_employeeNum;
}

void Employee::setEmployeeName(const string& name)
{
	m_employeeName = name;
}

void Employee::setEmployeeNum(int WorkerNum)
{
	m_employeeNum = WorkerNum;
}

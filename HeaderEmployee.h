#pragma once

#include <fstream>
#include <iostream>
#include <String>
using namespace std;
#pragma warning (disable:4996)


class Employee
{
public:
	Employee(const string& name) throw(const char*);
	virtual ~Employee(){}
public:
	const string& getEmployeeName() const;
	int getEmployeeNum() const;

	void setEmployeeName(const string& name);
	void setEmployeeNum(int employeeNum);

protected:
	static int counter;
	string m_employeeName;
	int m_employeeNum;

};
#pragma once

#include "HeaderEmployee.h"


class Nurse:public Employee
{

public:

	Nurse(const string& name, int exp) throw(const char*) :Employee(name), m_exp(exp)
	{
		if (exp < 0)
			throw "Invalid experience!";
		else if (name.empty())
			throw "Invalid name!";
	}
	friend ostream& operator<<(ostream& os, const Nurse& nurse);

public:
	
	int getNurseExp() const;
	void setExp(int exp);
	

private:
	int	m_exp;
};
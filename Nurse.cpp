#include "HeaderNurse.h"



int Nurse::getNurseExp() const
{
	return m_exp;
}

void Nurse::setExp(int exp)
{
	m_exp = exp;
}


ostream& operator<<(ostream& os, const Nurse& nurse)
{
	os << "Name: " << nurse.m_employeeName << endl;
	os << "Employee number: " << nurse.m_employeeNum << endl;
	os << "Nurse experience: " << nurse.m_exp << endl;
	return os;
}

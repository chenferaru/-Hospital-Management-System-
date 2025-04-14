#pragma once

#include "HeaderEmployee.h"


class Doctor : virtual public Employee
{
public:
	
	Doctor(const string& name, const string& speciality) throw(const char*);
	const Doctor& operator=(const Doctor& other) = delete;
	virtual ~Doctor(){}
public:
	
	const string& getDoctorSpeciality() const;
	void setDoctorSpeciality(const string& speciality);
	virtual void toOs(ostream& os) const {};
	friend ostream& operator<<(ostream& os, const Doctor& doctor)
	{
		os << "Name: " << doctor.m_employeeName << endl;
		os << "Employee number: " << doctor.m_employeeNum << endl;
		os << "Specialty: " << doctor.m_speciality << endl;
		doctor.toOs(os);
		return os;
	}

protected:
	string m_speciality;
};


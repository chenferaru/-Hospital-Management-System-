#pragma once

#include "HeaderNurse.h"
#include "HeaderDoctor.h"
#include "HeaderEmployee.h"
#include "HeaderSurgeon.h"
#include "SurgeonResearcher.h"
#include "DoctorResearcher.h"
#include "Array.h"

class Department
{
public:
	Department(const string& departmentName) throw(const char*);
	Department(const Department& other) = delete;
	Department(Department&& other) = delete;
	const Department& operator=(const Department& other) = delete;
	~Department();

public:
	const string& getDepartmentName() const;
	const vector<Nurse*>& getAllNurses() const;
	Array<Doctor*>& getAllDoctors();
	void setDepartmentName(const string& name);
	void addNurse(const string&, int exp);
	Department* operator+=(Doctor* other);
	
private:

	string m_departmentName;
	vector<Nurse*> m_allNurses;

	Array<Doctor*> m_allDoctors;

};
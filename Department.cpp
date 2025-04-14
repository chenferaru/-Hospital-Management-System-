#include "HeaderDepartment.h"
#include "HeaderNurse.h"

Department::Department(const string& departmentName)
{
	if (departmentName.empty())
		throw "Invalid name!";
	setDepartmentName(departmentName);
}

Department::~Department()
{
	vector<Nurse*>::iterator itr = m_allNurses.begin();
	vector<Nurse*>::iterator itrEnd = m_allNurses.end();

	for (; itr != itrEnd; ++itr)
	{
		delete (*itr);
	}

	
	for (int i = 0; i < m_allDoctors.size(); i++)
	{
		delete m_allDoctors[i];
	}
}

const string& Department::getDepartmentName() const
{
	return m_departmentName;
}

const vector<Nurse*>& Department::getAllNurses() const
{
	return m_allNurses;
}

Array<Doctor*>& Department::getAllDoctors()
{
	return m_allDoctors;
}

void Department::setDepartmentName(const string& name)
{
	m_departmentName = name;
}

void Department::addNurse(const string& name, int exp)
{
	Nurse* newNurse = new Nurse(name, exp);
	m_allNurses.push_back(newNurse);
	if (m_allNurses.size() == m_allNurses.capacity())
		m_allNurses.reserve(m_allNurses.size() * 2);
}

Department* Department::operator+=(Doctor* other)
{
	m_allDoctors.push_back(other);
	if (m_allDoctors.size() == m_allDoctors.capacity())
		m_allDoctors.reserve(m_allDoctors.size() * 2);
	return this;
}
#include "HeaderVisitCard.h"

const char* genderValues[] = { "Men","Women" };

VisitCard::VisitCard(const string& name, int id, int birthYear, eGender gender, Date arriveDate, const string& visitPurpose, Doctor* attendingDoc, Department* department)
	: m_arriveDate(arriveDate)
{
	if (id < 0)
		throw "Invalid id";
	else if (birthYear < 0)
		throw "Invalid birth year";
	else if (name.empty())
		throw "Invalid name!";
	else if (visitPurpose.empty())
		throw "Invalid visit purpose";
	setPatientName(name);
	m_id = id;
	setPatientBirthdayYear(birthYear);
	setGender(gender);
	setVisitPurpose(visitPurpose);
	setAttendingDoc(attendingDoc);
	setDepartment(department);
}

const string& VisitCard::getPatientName() const
{
	return m_name;
}

int VisitCard::getPatientId() const
{
	return m_id;
}

int VisitCard::getPatientBirthdayYear() const
{
	return m_birthYear;
}

VisitCard::eGender VisitCard::getPatientGender() const
{
	return m_gender;
}

Date VisitCard::getPatientDate() const
{
	return m_arriveDate;
}

const string& VisitCard::getPatientVisitPurpose() const
{
	return m_visitPurpose;
}

Doctor* VisitCard::getAttendingDoc() const
{
	return m_attendingDoc;
}

Department* VisitCard::getPatientDepartment() const
{
	return m_department;
}

void VisitCard::setPatientName(const string& name)
{
	m_name = name;
}

void VisitCard::setPatientBirthdayYear(int birthday)
{
	m_birthYear = birthday;
}

void VisitCard::setGender(eGender gender)
{
	m_gender = gender;
}

void VisitCard::setArriveDate(Date arriveDate)
{
	m_arriveDate = arriveDate;
}

void VisitCard::setVisitPurpose(const string& visitPurpose)
{
	m_visitPurpose = visitPurpose;
}

void VisitCard::setAttendingDoc(Doctor* doc)
{
	m_attendingDoc = doc;
}

void VisitCard::setDepartment(Department* department)
{
	m_department = department;
}

void VisitCard::show()
{
	cout << "Patient name: " << m_name << endl;
	cout << "Id number: " << m_id << endl;
	cout << "Birthday year: " << m_birthYear << endl;
	cout << "Gender: " << genderValues[(int)m_gender] << endl;
	m_arriveDate.printDate();
	cout << "Visit purpose: " << m_visitPurpose << endl;
	cout << "Attending doctor name: " << m_attendingDoc->getEmployeeName() << endl;
	cout << "Department: " << m_department->getDepartmentName() << endl<< endl;
}

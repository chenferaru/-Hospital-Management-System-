#pragma once

#include "HeaderDate.h"
#include "HeaderDoctor.h"
#include "HeaderDepartment.h"

class VisitCard
{
public:

	enum class eGender { MEN, WOMEN };

public:

	VisitCard(const string& name, int id, int birthYear, eGender gender, Date arriveDate, const string& visitPurpose, Doctor* attendingDoc, Department* department) throw(const char*);

public:

	const string& getPatientName() const;
	int getPatientId() const;
	int getPatientBirthdayYear() const;
	eGender getPatientGender() const;
	Date getPatientDate() const;
	const string& getPatientVisitPurpose() const;
	Doctor* getAttendingDoc() const;
	Department* getPatientDepartment() const;

	void setPatientName(const string& name);
	void setPatientBirthdayYear(int birthday);
	void setGender(eGender gender);
	void setArriveDate(Date arriveDate);
	void setVisitPurpose(const string& m_visitPurpose);
	void setAttendingDoc(Doctor* doc);
	void setDepartment(Department* department);

	virtual void show();
protected:
	string m_name;
	int	m_id;
	int	m_birthYear;
	eGender m_gender;

	Date m_arriveDate;
	string m_visitPurpose;
	Doctor* m_attendingDoc;
	Department* m_department;
};


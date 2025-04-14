#pragma once

#include "HeaderVisitCard.h"

class PatientForSurgeon : public VisitCard
{
public:
	PatientForSurgeon(const string& name, int id, int birthYear, eGender gender, Date arriveDate, const string& visitPurpose, Doctor* attendingDoc, Department* department, int fasting, int treatmentRoom) throw(const char*)
		: VisitCard(name, id, birthYear, gender, arriveDate, visitPurpose, attendingDoc, department), m_fasting(fasting), m_treatmentRoom(treatmentRoom)
	{
		if (!(fasting == 0 || fasting == 1))
			throw "Invalid fasting value";
		else if (treatmentRoom < 0)
			throw "Invalid treatment room";
	}
	virtual ~PatientForSurgeon(){}

public:
	int getFasting() const;
	int getTreatmentRoom() const;

	void setFasting(int fasting);
	void setTreatmentRoom(int treatmentRoom);

	void show() override;


private:
	int m_fasting;
	int m_treatmentRoom;
};
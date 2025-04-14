#pragma once

#include <vector>
#include "HeaderResearch.h"
#include "HeaderVisitCard.h"

const int MAX_SIZE = 256;

class Hospital
{

public:
	Hospital();
	Hospital(const Hospital& other) = delete;
	~Hospital();

public:

	vector<Department*>& getAllDepartments();
	Research* getReasearch();
	vector<VisitCard*>& getAllVisitCards();
	
	void addDepartment(char* departmentName);
	void addVisit(int idNumber);
	bool validGender(int gender);
	void showAllPatientsAccordingDepartment(Department* department);
	void showAllStaff();
	void showAllDoctors();
	void showAllReaserchers();
	void searchPatient(int id);
	void addPatientForSurg(int idNumber);

private:

	vector<Department*> m_allDepartments;
	Research* m_Research;
	vector<VisitCard*> m_allVisitCards;

};
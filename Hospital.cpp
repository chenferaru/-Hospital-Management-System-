#include "HeaderHospital.h"
#include "HeaderVisitCard.h"
#include "PatientForSurg.h"

#include <iostream>
using namespace std;

Hospital::Hospital()
{
	m_Research = new Research();
}

Hospital::~Hospital()
{
	delete m_Research;

	vector<Department*>::iterator itrD = m_allDepartments.begin();
	vector<Department*>::iterator itrDEnd = m_allDepartments.end();
	for (; itrD != itrDEnd; ++itrD)
	{
		delete (*itrD);
	}

	vector<VisitCard*>::iterator itrV = m_allVisitCards.begin();
	vector<VisitCard*>::iterator itrVEnd = m_allVisitCards.end();

	for (; itrV != itrVEnd; ++itrV)
	{
		delete (*itrV);
	}
}

vector<Department*>& Hospital::getAllDepartments()
{
	return m_allDepartments;
}

Research* Hospital::getReasearch()
{
	return m_Research;
}

vector<VisitCard*>& Hospital::getAllVisitCards()
{
	return m_allVisitCards;
}

void Hospital::addDepartment(char* departmentName)
{
	Department* newDepartment = new Department(departmentName);

	m_allDepartments.push_back(newDepartment);
	if (m_allDepartments.size() == m_allDepartments.capacity())
		m_allDepartments.reserve(m_allDepartments.size() * 2);
}

void Hospital::addVisit(int idNumber)
{
	int forSurgery = 0;
	bool isPastPatient = false;
	int patientIndex;
	
	if (m_allDepartments.size() == 0)
		cout << "There is no department in the hospital, please create one and then add a new visit card" << endl;
	else
	{
		int birthYear, gender;
		char name[MAX_SIZE];
		bool isExistDepartment = false, isExistDoctor = false;
		VisitCard* newVisitCard;
		
		
		for (int i = 0; i < m_allVisitCards.size() && !isPastPatient; i++)
		{
			if (m_allVisitCards[i]->getPatientId() == idNumber)
			{
				patientIndex = i;
				isPastPatient = true;
			}
		}
		if (!isPastPatient)
		{
			cout << "Name: " ;
			cin.getline(name, MAX_SIZE);
			cout << "Birth year: ";
			cin >> birthYear;
			cout << "Gender (0 - Men, 1 - Women): ";
			cin >> gender;
			if (!validGender(gender))
			{
				cout << "Gender have to be 0 or 1" << endl << endl;;
				return;
			}
		}
		int day, month, year, departmentIndex, attendingDocIndex;
		char visitPurpose[MAX_SIZE], attendingDoc[MAX_SIZE], departmente[MAX_SIZE];
		cout << "Date:" << endl << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		getchar();
		
		cout << "Visit purpose: ";
		cin.getline(visitPurpose, MAX_SIZE);
		cout << "Attending doctor: ";
		cin.getline(attendingDoc, MAX_SIZE);
		cout << "Department: ";
		cin.getline(departmente, MAX_SIZE);
		for (int i = 0; i < m_allDepartments.size() && !isExistDepartment; i++)
		{
			if (m_allDepartments[i]->getDepartmentName() == (string)departmente)
			{
				isExistDepartment = true;
				departmentIndex = i;
			}
		}
		if (!isExistDepartment)
		{
			cout << "This department did not exist" << endl << endl;
			return;
		}
		for (int i = 0; i < m_allDepartments[departmentIndex]->getAllDoctors().size() && !isExistDoctor; i++)
		{
			if (m_allDepartments[departmentIndex]->getAllDoctors()[i]->getEmployeeName() == (string)attendingDoc)
			{
				isExistDoctor = true;
				attendingDocIndex = i;
			}
		}
		if (!isExistDoctor)
		{
			cout << "This doctor did not exist." << endl << endl;
			return;
		}
		Date arriveDate(day, month, year);
		if (!isPastPatient)
			newVisitCard = new VisitCard(name, idNumber, birthYear, (VisitCard::eGender)gender, arriveDate, visitPurpose, m_allDepartments[departmentIndex]->getAllDoctors()[attendingDocIndex], m_allDepartments[departmentIndex]);
		else
			newVisitCard = new VisitCard(m_allVisitCards[patientIndex]->getPatientName(), m_allVisitCards[patientIndex]->getPatientId(), m_allVisitCards[patientIndex]->getPatientBirthdayYear(), m_allVisitCards[patientIndex]->getPatientGender(), arriveDate, visitPurpose, m_allDepartments[departmentIndex]->getAllDoctors()[attendingDocIndex], m_allDepartments[departmentIndex]);

		m_allVisitCards.push_back(newVisitCard);
		if (m_allDepartments.size() == m_allVisitCards.capacity())
			m_allDepartments.reserve(m_allVisitCards.capacity() * 2);
		cout << "Visit successfully added!" << endl << endl;
	}
}

void Hospital::showAllPatientsAccordingDepartment(Department* department)
{
	for (int i = 0; i < m_allDepartments.size(); i++)
	{
		if (m_allVisitCards[i]->getPatientDepartment() == department)
			m_allVisitCards[i]->show();
	}
}

void Hospital::showAllStaff()
{
	for (int i = 0; i < m_allDepartments.size(); i++)
	{
		for (int j = 0; j < m_allDepartments[i]->getAllNurses().size(); j++)
		{
			cout << *m_allDepartments[i]->getAllNurses()[j] << endl;
		}
	for (int j = 0; j < m_allDepartments[i]->getAllDoctors().size(); j++)
		{
			cout << *m_allDepartments[i]->getAllDoctors()[j] << endl;
		}
	}
}

void Hospital::showAllDoctors()
{
	for (int i = 0; i < m_allDepartments.size(); i++)
	{
		for (int j = 0; j < m_allDepartments[i]->getAllDoctors().size(); j++)
		{

			cout << *m_allDepartments[i]->getAllDoctors()[j] << endl;

		}
	}
}

void Hospital::showAllReaserchers()
{
	for (int i = 0; i < m_Research->getAllReasearchers().size(); i++)
	{
		m_Research->getAllReasearchers()[i]->show();
	}
}

void Hospital::searchPatient(int id)
{
	int visitTimes = 0;
	for (int i = 0; i < m_allVisitCards.size(); i++)
	{
		if (m_allVisitCards[i]->getPatientId() == id)
		{
			visitTimes++;
			m_allVisitCards[i]->show();
			cout << endl;
		}
	}
	if (visitTimes == 0)
		cout << "According to this id number, the patient does not have a visit card in the system." << endl;
}

bool Hospital::validGender(int gender)
{
	return gender == 0 || gender == 1;
}

void Hospital::addPatientForSurg(int idNumber)
{
	int forSurgery = 0;
	bool isPastPatient = false;
	int patientIndex, roomNumber;
	
	if (m_allDepartments.size() == 0)
		cout << "There is no department in the hospital, please create one and then add a new visit card" << endl;
	else
	{
		int birthYear, gender, fast;
		char name[MAX_SIZE];
		bool isExistDepartment = false, isExistDoctor = false;
		
		PatientForSurgeon* newVisitCard;
		cout << "Does the patient in a fast? (0 - No, 1 - Yes):" << endl;
		cin >> fast;

		for (int i = 0; i < m_allVisitCards.size() && !isPastPatient; i++)
		{
			if (m_allVisitCards[i]->getPatientId() == idNumber)
			{
				patientIndex = i;
				isPastPatient = true;
			}
		}
		if (!isPastPatient)
		{
			cout << "Name: \n";
			getchar();
			cin.getline (name, MAX_SIZE);
			cout << "Birth year: ";
			cin >> birthYear;
			cout << "Gender (0 - Men, 1 - Women): ";
			cin >> gender;
			if (!validGender(gender))
			{
				cout << "Gender have to be 0 or 1" << endl << endl;;
				return;
			}
		}
		int day, month, year, departmentIndex, attendingDocIndex;
		char visitPurpose[MAX_SIZE], attendingDoc[MAX_SIZE], departmente[MAX_SIZE];
		cout << "Date:" << endl << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		getchar();

		cout << "Surgery purpose: ";
		cin.getline(visitPurpose, MAX_SIZE);
		cout << "Attending doctor: ";
		cin.getline(attendingDoc, MAX_SIZE);
		cout << "Department: ";
		cin.getline(departmente, MAX_SIZE);
		cout << "Room number: ";
		cin >> roomNumber;
		for (int i = 0; i < m_allDepartments.size() && !isExistDepartment; i++)
		{
			if (m_allDepartments[i]->getDepartmentName() == departmente)
			{
				isExistDepartment = true;
				departmentIndex = i;
			}
		}
		if (!isExistDepartment)
		{
			cout << "This department did not exist" << endl << endl;
			return;
		}
		for (int i = 0; i < m_allDepartments[departmentIndex]->getAllDoctors().size() && !isExistDoctor; i++)
		{
			if (m_allDepartments[departmentIndex]->getAllDoctors()[i]->getEmployeeName() ==  (string)attendingDoc)
			{
				isExistDoctor = true;
				attendingDocIndex = i;
			}
		}
		if (!isExistDoctor)
		{
			cout << "This doctor did not exist." << endl << endl;
			return;
		}
		Date arriveDate(day, month, year);;
		if (!isPastPatient)
			newVisitCard = new PatientForSurgeon(name, idNumber, birthYear, (VisitCard::eGender)gender, arriveDate, visitPurpose, m_allDepartments[departmentIndex]->getAllDoctors()[attendingDocIndex], m_allDepartments[departmentIndex],fast, roomNumber);
		else
			newVisitCard = new PatientForSurgeon(m_allVisitCards[patientIndex]->getPatientName(), m_allVisitCards[patientIndex]->getPatientId(), m_allVisitCards[patientIndex]->getPatientBirthdayYear(), m_allVisitCards[patientIndex]->getPatientGender(), arriveDate, visitPurpose, m_allDepartments[departmentIndex]->getAllDoctors()[attendingDocIndex], m_allDepartments[departmentIndex],fast,roomNumber);

		m_allVisitCards.push_back(newVisitCard);
		if (m_allDepartments.size() == m_allVisitCards.capacity())
			m_allDepartments.reserve(m_allVisitCards.capacity() * 2);

		cout << "Visit successfully added!" << endl << endl;
	}
}

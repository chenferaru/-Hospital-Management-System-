#include "HeaderMain.h"
#include <algorithm>
#include <fstream>

void printMenu()
{
	cout << " 1 - Add new department to the hospital." << endl
		 << " 2 - Add new nurse to the hospital." << endl
	 	 << " 3 - Add new regular doctor to the hospital." << endl
		 << " 4 - Add new patient (not for surgery)." << endl
		 << " 5 - Add new regular researcher to the research institue." << endl
		 << " 6 - Add article to researcher." << endl
		 << " 7 - Print all the patients in specific department: " << endl
		 << " 8 - Print all the employees in the depatrments" << endl
		 << " 9 - Print all the researchers including the doctors researchers" << endl
		 << "10 - Printing patient history according id number." << endl
		 << "11 - Add surgeon doctor to the hospital" << endl
		 << "12 - Add patient for surgery" << endl
		 << "13 - Add doctor researcher to the research institue" << endl
		 << "14 - Add surgery researcher to the research institue" << endl
		 << "15 - Compare 2 researchers by the number of articles thay have" << endl
	 	 << "16 - Print all the doctors in the departments" << endl
		 << "17 - Print the name of the first researcher with more then one article" << endl
		 << "18 - Print how many patient was born in 2000" << endl
		 << "0 - Exit." << endl;
}

void makeAction(int clientChoose, Hospital& myHospital)
{
	switch (clientChoose)
	{
	case 1:
		addDepartment(myHospital);
		break;
	case 2:
		addNurse(myHospital);
		break;
	case 3 :
		addDoctor(myHospital);
		break;
	case 4 :
		addVisitCard(myHospital);
		break;
	case 5:
		addResearcher(myHospital);
		break;
	case 6:
		addArticle(myHospital);
		break;
	case 7: 
		showAllPatient(myHospital);
		break;
	case 8:
		myHospital.showAllStaff();
		break;
	case 9:
		myHospital.getReasearch()->showAllResearchers();
		break;
	case 10:
		showPatientHistory(myHospital);
		break;
	case 11:
		addSurgeon(myHospital);
		break;
	case 12:
		addPatientForSurg(myHospital);
		break;
	case 13:
		addDoctorResearcher(myHospital);
		break;
	case 14:
		addSurgeonResearcher(myHospital);
		break;
	case 15:
		CompareResearchers(myHospital);
		break;
	case 16:
		myHospital.showAllDoctors();
		break;
	case 17:
		moreThenOneArticle(myHospital);
		break;
	case 18:
		bornIn(myHospital.getAllVisitCards());
		break;
	case 0:
		cout << "Thank you and goodbye!!!";
		break;
	default:
		break;
	}
}

void addDepartment(Hospital& myHospital)
{
	char departmentName[MAX_SIZE];
	cout << "Type the department name: ";
	cin.getline(departmentName, MAX_SIZE);
	try
	{
		myHospital.addDepartment(departmentName);
		cout << "Department successfully added" << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl << endl;
	}
}

void addNurse(Hospital& myHospital)
{
	char departmentName[MAX_SIZE];
	char name[MAX_SIZE];
	int exp, departmentIndex;
	bool departmentExist = false;
	cout << "Type the department name: ";
	cin.getline(departmentName, MAX_SIZE);
	for (int i = 0; i < myHospital.getAllDepartments().size() && !departmentExist; i++)
	{
		if (myHospital.getAllDepartments()[i]->getDepartmentName() == (string)departmentName)
		{
			departmentExist = true;
			departmentIndex = i;
		}
	}
	if (departmentExist)
	{
		cout << "Nurse name: ";
		cin.getline(name, MAX_SIZE);
		cout << "Nurse experience: ";
		cin >> exp;
		try
		{
			myHospital.getAllDepartments()[departmentIndex]->addNurse(name, exp);
			cout << "Nurse successfully added!" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
	}
	else
		cout << "Sorry, this department does not exist." << endl << endl;
}

void addDoctor(Hospital& myHospital)
{
	char doctorName[MAX_SIZE], speciality[MAX_SIZE], departmentName[MAX_SIZE];
	int departmentIndex;
	bool departmentExist = false;
	cout << "Type the department name: ";
	cin.getline(departmentName, MAX_SIZE);
	for (int i = 0; i < myHospital.getAllDepartments().size() && !departmentExist; i++)
	{
		if (myHospital.getAllDepartments()[i]->getDepartmentName() == (string)departmentName)
		{
			departmentExist = true;
			departmentIndex = i;
		}
	}
	if (departmentExist)
	{
		cout << "Doctor name: ";
		cin.getline(doctorName, MAX_SIZE);
		cout << "Doctor speciality: ";
		cin.getline(speciality, MAX_SIZE);
		try
		{
			Doctor* newDoctor = new Doctor(doctorName, speciality);
			myHospital.getAllDepartments()[departmentIndex]->operator+=(newDoctor);

			cout << "Doctor successfully added!" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
	}
	else
		cout << "Sorry, this department does not exist." << endl << endl;
}

void addSurgeon(Hospital& myHospital)
{
	char surgeonName[MAX_SIZE], speciality[MAX_SIZE], departmentName[MAX_SIZE];
	int  departmentIndex, numOfSurg;
	bool departmentExist = false;
	cout << "Type the department name: ";
	cin.getline(departmentName, MAX_SIZE);
	for (int i = 0; i < myHospital.getAllDepartments().size() && !departmentExist; i++)
	{
		if (myHospital.getAllDepartments()[i]->getDepartmentName() == (string)departmentName)
		{
			departmentExist = true;
			departmentIndex = i;
		}
	}
	if (departmentExist)
	{
		try
		{
			cout << "Doctor name: ";
			cin.getline(surgeonName, MAX_SIZE);
			cout << "Doctor speciality: ";
			cin.getline(speciality, MAX_SIZE);
			cout << "Number of surgeries: ";
			cin >> numOfSurg;
			Surgeon* newSurgeon = new Surgeon(surgeonName, speciality, numOfSurg);
			myHospital.getAllDepartments()[departmentIndex]->operator+=(newSurgeon);
			cout << "Doctor successfully added!" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
	}
	else
		cout << "Sorry, this department does not exist." << endl << endl;
}

void addVisitCard(Hospital& myHospital)
{
	int idNumber;

	cout << "Type patient's id number: ";
	cin >> idNumber;
	getchar();
	try
	{
		myHospital.addVisit(idNumber);
	}
	catch (const char* msg)
	{
		cout << msg << endl << endl;
	}
}

void addPatientForSurg(Hospital& myHospital)
{
	int idNumber;

	cout << "Type patient's id number: ";
	cin >> idNumber;
	getchar();
	try
	{
		myHospital.addPatientForSurg(idNumber);
	}
	catch(const char* msg)
	{
		cout << msg << endl << endl;
	}
}


void addResearcher(Hospital& myHospital)
{
	char name[MAX_SIZE];
	cout << "Researcher name: ";
	cin.getline(name, MAX_SIZE);
	try
	{
		myHospital.getReasearch()->addResearcher(name);
		cout << "Researcher successfully added!" << endl << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl << endl;
	}
}

void addDoctorResearcher(Hospital& myHospital)
{
	char name[MAX_SIZE], speciality[MAX_SIZE];
	cout << "Name: ";
	cin.getline(name, MAX_SIZE);
	cout << "Speciality: ";
	cin.getline(speciality, MAX_SIZE);
	try
	{
		myHospital.getReasearch()->addDoctorResearcher(name, speciality);
		cout << "Researcher successfully added!" << endl << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl << endl;
	}
}

void addSurgeonResearcher(Hospital& myHospital)
{
	char name[MAX_SIZE], speciality[MAX_SIZE];
	int numOfSurg;
	cout << "Name: ";
	cin.getline(name, MAX_SIZE);
	cout << "Speciality: ";
	cin.getline(speciality, MAX_SIZE);
	cout << "Number of surgeries: ";
	cin >> numOfSurg;
	try
	{
		myHospital.getReasearch()->addSurgeonResearcher(name, speciality, numOfSurg);
		cout << "Researcher successfully added!" << endl << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl << endl;
	}

}

void addArticle(Hospital& myHospital)
{
	char researcherName[MAX_SIZE], magazineName[MAX_SIZE], articleName[MAX_SIZE];
	int day, month, year, researcherIndex;
	bool researcherExist = false;
	cout << "Type the researcher name: ";
	cin.getline(researcherName, MAX_SIZE);
	for (int i = 0; i < myHospital.getReasearch()->getAllReasearchers().size() && !researcherExist; i++)
	{
		if (myHospital.getReasearch()->getAllReasearchers()[i]->getEmployeeName() == (string)researcherName)
		{
			researcherExist = true;
			researcherIndex = i;
		}
	}
	if (researcherExist)
	{
		cout << "Article name: ";
		cin.getline(articleName, MAX_SIZE);
		cout << "Magazine name: ";
		cin.getline(magazineName, MAX_SIZE);
		cout << "Date:" << endl;
		cout << "Day: ";
		cin >> day;
		cout << "Month:";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		try
		{
			Date date = Date(day, month, year);
			myHospital.getReasearch()->getAllReasearchers()[researcherIndex]->addArticle(date, magazineName, articleName);
			cout << "Article successfully added!" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
	}
	else
		cout << "Sorry, this researcher does not exist." << endl << endl;
}

void showAllPatient(Hospital& myHospital)
{
	char departmentName[MAX_SIZE];
	int departmentIndex;
	bool departmentExist = false;
	cout << "Type the department name: ";
	cin.getline(departmentName, MAX_SIZE);
	for (int i = 0; i < myHospital.getAllDepartments().size() && !departmentExist; i++)
	{
		if (myHospital.getAllDepartments()[i]->getDepartmentName() == (string)departmentName)
		{
			departmentExist = true;
			departmentIndex = i;
		}
	}
	if (departmentExist)
	{
		cout << endl;
		myHospital.showAllPatientsAccordingDepartment(myHospital.getAllDepartments()[departmentIndex]);
		cout << endl << endl;
	}
	else
		cout << "Sorry, this department does not exist." << endl << endl;
}

void showPatientHistory(Hospital& myHospital)
{
	int id;
	cout << "Patient id number: ";
	cin >> id;
	myHospital.searchPatient(id);
	cout << endl << endl;
}

void CompareResearchers(Hospital& myHospital)
{
	char researcher1Name[MAX_SIZE], researcher2Name[MAX_SIZE];
	int researcher1Index, researcher2Index;
	bool researcher1Exist = false;
	bool researcher2Exist = false;
	cout << "Type the first researcher name: ";
	cin.getline(researcher1Name, MAX_SIZE);
	cout << "Type the second researcher name: ";
	cin.getline(researcher2Name, MAX_SIZE);

	for (int i = 0; i < myHospital.getReasearch()->getAllReasearchers().size() && !researcher1Exist; i++)
	{
		if (myHospital.getReasearch()->getAllReasearchers()[i]->getEmployeeName() == researcher1Name)
		{
			researcher1Exist = true;
			researcher1Index = i;
		}
	}
	if (researcher1Exist)
	{
		for (int i = 0; i < myHospital.getReasearch()->getAllReasearchers().size() && !researcher2Exist; i++)
		{
			if (myHospital.getReasearch()->getAllReasearchers()[i]->getEmployeeName() == (string)researcher2Name)
			{
				researcher2Exist = true;
				researcher2Index = i;
			}
		}
		if (researcher2Exist)
		{
			if (*(myHospital.getReasearch()->getAllReasearchers()[researcher1Index]) > *(myHospital.getReasearch()->getAllReasearchers()[researcher2Index]))
				cout << myHospital.getReasearch()->getAllReasearchers()[researcher1Index]->getEmployeeName() << " has more articles than " << myHospital.getReasearch()->getAllReasearchers()[researcher2Index]->getEmployeeName() << endl << endl;

			else if (*(myHospital.getReasearch()->getAllReasearchers()[researcher2Index]) > *(myHospital.getReasearch()->getAllReasearchers()[researcher1Index]))
				cout << myHospital.getReasearch()->getAllReasearchers()[researcher2Index]->getEmployeeName() << " has more articles than " << myHospital.getReasearch()->getAllReasearchers()[researcher1Index]->getEmployeeName() << endl << endl;
			else
				cout << "They have the same number of articles" << endl << endl;
			
		}

	}
	else
		cout << "Sorry, this researcher does not exist." << endl << endl;
}

bool isMoreThenOneArticle(Researcher* researcher)
{
	if (researcher->getSllArticles().size() > 1)
		return true;
	return false;
}

void moreThenOneArticle(Hospital& myHospital)
{
	vector<Researcher*>::iterator found = find_if(myHospital.getReasearch()->getAllReasearchers().begin(), myHospital.getReasearch()->getAllReasearchers().end(), isMoreThenOneArticle);
	if (found == myHospital.getReasearch()->getAllReasearchers().end())
		cout << "There is no researcher with more then one article" << endl << endl;
	else
		cout << "The first researcher with more then ont article is: " << (*found)->getEmployeeName() << endl << endl;
}

bool isBornInTwoThousand(VisitCard* visitCard)
{
	if (visitCard->getPatientBirthdayYear() == 2000)
		return true;
	return false;
}

void bornIn(vector<VisitCard*>& visitCards)
{
	int numOfBorns = count_if(visitCards.begin(), visitCards.end(), isBornInTwoThousand);
	cout << "There are " << numOfBorns << " patients that born in 2000" << endl << endl;
}
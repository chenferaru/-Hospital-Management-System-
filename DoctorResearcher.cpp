#include "DoctorResearcher.h"


DoctorResearcher::DoctorResearcher(const string& name, const string& speciality): Employee(name), Doctor(name,speciality), Researcher(name){}

void DoctorResearcher::show()
{
	cout << "Doctor Researcher:" << endl;
	cout << "Name: " << m_employeeName << endl;
	cout << "Employee number: " << m_employeeNum << endl;
	cout << "Speciality: " << m_speciality << endl;
	cout << "Articles: " << endl;

	vector<Article*>::iterator itr = m_allArticles.begin();
	vector<Article*>::iterator itrEnd = m_allArticles.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->show();
	}
}


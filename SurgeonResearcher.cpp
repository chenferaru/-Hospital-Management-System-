#include "SurgeonResearcher.h"


SurgeonResearcher::SurgeonResearcher(const string& name, const string& speciality, int numOfOperations) : Employee(name), Surgeon(name, speciality, numOfOperations), Researcher(name)
{
}


void SurgeonResearcher::show()
{
	cout << "Surgeon Researcher:" << endl;
	cout << "Name: " << m_employeeName << endl;
	cout << "Employee number: " << m_employeeNum << endl;
	cout << "Speciality: " << m_speciality << endl;
	cout << "Number of surgeries: " << m_numOfOperations << endl;
	cout << "Articles: " << endl;
	vector<Article*>::iterator itr = m_allArticles.begin();
	vector<Article*>::iterator itrEnd = m_allArticles.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->show();
	}
}


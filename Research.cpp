#include "HeaderResearch.h"
#include "HeaderResearcher.h"
#include "DoctorResearcher.h"
#include "SurgeonResearcher.h"


Research::~Research()
{
	vector<Researcher*>::iterator itr = m_AllReasearchers.begin();
	vector<Researcher*>::iterator itrEnd = m_AllReasearchers.end();
	for (; itr!=itrEnd; ++itr)
	{
		delete (*itr);
	}
}

vector<Researcher*>& Research::getAllReasearchers()
{
	return m_AllReasearchers;
}

void Research::addResearcher(const string& name)
{
	Researcher* newReasearcher = new Researcher(name);
	m_AllReasearchers.push_back(newReasearcher);
	if (m_AllReasearchers.capacity() == m_AllReasearchers.size())
		m_AllReasearchers.reserve(m_AllReasearchers.size() * 2);
}

void Research::addDoctorResearcher(const string& name, const string& speciality)
{
	DoctorResearcher* newDoctorResearcher = new DoctorResearcher(name, speciality);
	m_AllReasearchers.push_back(newDoctorResearcher);
	if (m_AllReasearchers.capacity() == m_AllReasearchers.size())
		m_AllReasearchers.reserve(m_AllReasearchers.size() * 2);

}


void Research::addSurgeonResearcher(const string& name, const string& speciality, int numOfSurg)
{
	SurgeonResearcher* newDoctorResearcher = new SurgeonResearcher(name, speciality,numOfSurg);
	m_AllReasearchers.push_back(newDoctorResearcher);
	if (m_AllReasearchers.capacity() == m_AllReasearchers.size())
		m_AllReasearchers.reserve(m_AllReasearchers.size() * 2);
}


void Research::showAllResearchers()
{
	vector<Researcher*>::iterator itr = m_AllReasearchers.begin();
	vector<Researcher*>::iterator itrEnd = m_AllReasearchers.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->show();
	}
}
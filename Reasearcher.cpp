#include "HeaderResearcher.h"

Researcher::Researcher(const string& name) : Employee(name)
{
	if (name.empty())
		throw "Invalid name!";
}


Researcher::~Researcher()
{
	if (m_allArticles.size() > 0)
	{
		vector<Article*>::iterator itr = m_allArticles.begin();
		vector<Article*>::iterator itrEnd = m_allArticles.end();
		for (; itr != itrEnd; ++itr)
		{
			delete (*itr);
		}
	}
}

vector<Article*>& Researcher::getSllArticles()
{
	return m_allArticles;
}

void Researcher::addArticle(Date& date, const string& magazineName, const string& articleName)
{
	Article* newArticle = new Article(date, magazineName, articleName);
	m_allArticles.push_back(newArticle);
	if (m_allArticles.size() == m_allArticles.capacity())
		m_allArticles.reserve(m_allArticles.size() * 2);
}

void Researcher::show()
{
	cout << "Name: " << m_employeeName << endl;
	cout << "Employee number: " << m_employeeNum << endl;
	cout << "Articles: " << endl;
	vector<Article*>::iterator itr = m_allArticles.begin();
	vector<Article*>::iterator itrEnd = m_allArticles.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->show();
	}
}

bool Researcher::operator>(const Researcher& other) const
{
	return m_allArticles.size() > other.m_allArticles.size();
}


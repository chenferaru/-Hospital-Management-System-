#pragma once

#include <vector>
#include "HeaderArticle.h"
#include "HeaderEmployee.h"



class Researcher: virtual public Employee
{
public:
	Researcher(const string& name) throw (const char*);
	Researcher(const Researcher& other) = delete;
	virtual ~Researcher();

public:
	vector<Article*>& getSllArticles();


	void addArticle(Date& date, const string& m_magazineName, const string& m_articleName);
	virtual void show();

	bool operator>(const Researcher& other) const;

protected:
	vector<Article*> m_allArticles;
};
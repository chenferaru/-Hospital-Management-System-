#pragma once

#include "HeaderDate.h"

class Article
{

public:
	Article(const Date& date, const string& magazineName, const string& articalName) throw(const char*);

public:
	Date getArticleDate() const;
	const string& getMagzineName() const;
	const string& getArticleName() const;
	
	void setArticleDate(const Date& date);
	void setArticleMagazineName(const string& magazineName);
	void setArticleName(const string& articleName);

	void show();
private:
	Date m_date;
	string m_magazineName;
	string m_articleName;
};
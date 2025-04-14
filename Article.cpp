#include "HeaderArticle.h"
#include "HeaderDate.h"

Article::Article(const Date& date, const string& magazineName, const string& articalName) : m_date(date)
{
	if (magazineName.empty())
		throw "Invalid magazine name!";
	else if (articalName.empty())
		throw "Invalid article name!";

	setArticleMagazineName(magazineName);
	setArticleName(articalName);
}

Date Article::getArticleDate() const
{
	return m_date;
}

const string& Article::getMagzineName() const
{
	return m_magazineName;
}

const string& Article::getArticleName() const
{
	return m_articleName;
}

void Article::setArticleDate(const Date& date)
{
	m_date = date;
}

void Article::setArticleMagazineName(const string& magazineName)
{
	m_magazineName = magazineName;
}

void Article::setArticleName(const string& articleName)
{
	m_articleName = articleName;
}

void Article::show()
{
	cout << "Article puplish date: ";
	m_date.printDate();
	cout << "Article name: " << m_articleName << endl;
	cout << "Article magazine name: " << m_magazineName << endl;
}
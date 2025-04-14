#include "HeaderDate.h"

Date::Date(int day, int month, int year)
{
	if (!(day > 0 && month > 0 && year > 0 && day <= 31 && month <= 12))
		throw "Invalid date!";
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setDay(int day)
{
	m_day = day;
}

void Date::setMonth(int month)
{
	m_month = month;
}

void Date::setYear(int year)
{
	m_year = year;
}

int Date::getDay() const
{
	return m_day;
}

int Date::getMonth() const
{
	return m_month;
}

int Date::getYear() const
{
	return m_year;
}

void Date::printDate() const
{
	if (m_day < 10)
		cout << "0" << m_day << "/";
	else
		cout << m_day << "/";
	if (m_month < 10)
		cout << "0" << m_month << "/";
	else
		cout << m_month << "/";
	cout << m_year << endl;
}
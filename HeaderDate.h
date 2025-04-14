#pragma once

#include <fstream>
#include <iostream>

#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Date
{
public:
	Date(int day, int month, int year) throw(const char*);

public:
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void printDate() const;

private:
	int	m_year;
	int	m_month;
	int m_day;
};
#pragma once
#include <vector>
#include "HeaderResearcher.h"
#include "DoctorResearcher.h"


class Research
{
public:
	~Research();

public:

	vector<Researcher*>& getAllReasearchers();
	
	void addResearcher(const string& name);
	void addDoctorResearcher(const string& name, const string& speciality);
	void addSurgeonResearcher(const string& name, const string& speciality, int numOfSurg);

	
	void showAllResearchers();
private:
	vector<Researcher*> m_AllReasearchers;
};



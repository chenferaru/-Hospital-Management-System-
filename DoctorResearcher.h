#pragma once
#include <fstream>
#include <iostream>


using namespace std;

#include "HeaderEmployee.h"
#include "HeaderResearcher.h"
#include "HeaderDoctor.h"

class DoctorResearcher : public Doctor, public Researcher
{
public:
	DoctorResearcher(const string& name, const string& speciality);
	virtual ~DoctorResearcher(){}
	void show();
};
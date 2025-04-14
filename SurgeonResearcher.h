#pragma once

#include "HeaderEmployee.h"
#include "HeaderResearcher.h"
#include "HeaderSurgeon.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:
	SurgeonResearcher(const string& name, const string& speciality,int numOfOperations);
	virtual ~SurgeonResearcher(){}
	virtual void show();
};
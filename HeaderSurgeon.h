#pragma once

#include "HeaderDoctor.h"


class Surgeon : public Doctor
{
public:

	Surgeon(const string& name, const string& speciality, int numOfOperations) throw(const char*);
	virtual ~Surgeon() {}
public:
	int getNumOfOperations() const;
	void setNumOfOperations(int numOfOperations);

	//the operator << is a friend of the class
	virtual void toOs(ostream& os) const override { os << "Number of operations: " << m_numOfOperations << endl; }

	
protected:
	int m_numOfOperations;
};



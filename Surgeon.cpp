#include "HeaderSurgeon.h"


Surgeon::Surgeon(const string& name, const string& speciality, int numOfOperations) : Employee(name), Doctor(name, speciality)
{
	if (numOfOperations < 0)
	{
		throw "Invalid number of operation";
	}
	setNumOfOperations(numOfOperations);
}

void Surgeon::setNumOfOperations(int numOfOperations)
{
	m_numOfOperations = numOfOperations;
}

int Surgeon::getNumOfOperations() const
{
	return m_numOfOperations;
}






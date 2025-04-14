#include "HeaderDoctor.h"
#include "HeaderEmployee.h"

Doctor::Doctor(const string& name, const string& speciality) : Employee(name)
{
	if (speciality.empty())
		throw "Invalid speciality!";
	setDoctorSpeciality(speciality);
}

const string& Doctor::getDoctorSpeciality() const
{
	return m_speciality;
}

void Doctor::setDoctorSpeciality(const string& speciality)
{
	m_speciality = speciality;
}






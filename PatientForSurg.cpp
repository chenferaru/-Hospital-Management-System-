#include "PatientForSurg.h"




int PatientForSurgeon::getFasting() const
{
	return m_fasting;
}

int PatientForSurgeon::getTreatmentRoom() const
{
	return m_treatmentRoom;
}

void PatientForSurgeon::setFasting(int fasting)
{
	m_fasting = fasting;
}

void PatientForSurgeon::setTreatmentRoom(int treatmentRoom)
{
	m_treatmentRoom = treatmentRoom;
}

void PatientForSurgeon::show()
{
	VisitCard::show();
	if(m_fasting == 1)
		cout << "Fasting: Yes " << endl;
	else
		cout << "Fasting: No  " << endl;
		
	cout << "Treatment room: " << m_treatmentRoom << endl << endl;
}
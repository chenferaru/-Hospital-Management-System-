#pragma once


#include "HeaderArticle.h"
#include "HeaderDate.h"
#include "HeaderDepartment.h"
#include "HeaderDoctor.h"
#include "HeaderHospital.h"
#include "HeaderNurse.h"
#include "HeaderResearch.h"
#include "HeaderResearcher.h"
#include "HeaderVisitCard.h"


const int STOP = 0;

void printMenu();
void makeAction(int clientChoose, Hospital& myHospital);
void addDepartment(Hospital& myHospital);
void addNurse(Hospital& myHospital);
void addDoctor(Hospital& myHospital);
void addSurgeon(Hospital& myHospital);
void addVisitCard(Hospital& myHospital);
void addResearcher(Hospital& myHospital);
void addDoctorResearcher(Hospital& myHospital);
void addSurgeonResearcher(Hospital& myHospital);
void addArticle(Hospital& myHospital);
void showAllPatient(Hospital& myHospital);
void showPatientHistory(Hospital& myHospital);
void addPatientForSurg(Hospital& myHospital);
void CompareResearchers(Hospital& myHospital);
bool isMoreThenOneArticle(Researcher* researcher);
void moreThenOneArticle(Hospital& myHospital);
bool isBornInTwoThousand(VisitCard* visitCard);
void bornIn(vector<VisitCard*>& visitCards);



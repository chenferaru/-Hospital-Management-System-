#include "HeaderMain.h";
void main()
{
	 
	int i,j,k;
	Hospital myHospital;
	ifstream inFile("hospital.txt");
	int tmpNum1, tmpNum2, tmpNum3;
	int day, month, year;
	char tmpChar[128];
	char tmp2[128];
	char date[128];
	inFile.getline(tmpChar, 128);
	tmpNum1 = atoi(tmpChar);
	for (i = 0; i < tmpNum1; i++)
	{
		inFile.getline(tmpChar, 128);
		myHospital.addDepartment(tmpChar);

		inFile.getline(tmpChar, 128);
		tmpNum2 = atoi(tmpChar);
		for (j= 0; j< tmpNum2; j++)
		{
			inFile.getline(tmpChar, 128);
			inFile.getline(tmp2, 128);
			tmpNum3 = atoi(tmp2);

			myHospital.getAllDepartments()[i]->addNurse(tmpChar,tmpNum3);

		}

		inFile.getline(tmpChar, 128);
		tmpNum2 = atoi(tmpChar);
		for (j = 0; j < tmpNum2; j++)
		{
			inFile.getline(tmpChar, 128);
			inFile.getline(tmp2, 128);

			Doctor* newDoctor = new Doctor(tmpChar, tmp2);
			myHospital.getAllDepartments()[j]->operator+=(newDoctor);

		}


	}

	inFile.getline(tmpChar, 128);
	tmpNum1 = atoi(tmpChar);
	for (i = 0; i < tmpNum1; i++)
	{
		inFile.getline(tmpChar, 128);
		inFile.getline(tmp2, 128);
		tmpNum2 = atoi(tmp2);

		myHospital.getReasearch()->addResearcher(tmpChar);

		for ( j = 0; j < tmpNum2; j++)
		{
			inFile.getline(tmpChar, 128);
			inFile.getline(tmp2, 128);
			inFile.getline(date, 128);
			day = atoi(date);
			inFile.getline(date, 128);
			month = atoi(date);
			inFile.getline(date, 128);
			year = atoi(date);

			Date* d = new Date(day,month,year);

			myHospital.getReasearch()->getAllReasearchers()[i]->addArticle(*d,tmp2,tmpChar);

		}

	}



	inFile.close();
	ofstream outFile("hospital.txt");	
	int clientChoose;
	bool isCorrectChoose = true;
	do
	{
		printMenu();
		cout << endl << "Type your choice: ";
		cin >> clientChoose;
		getchar();
		cout << endl;
		if (!(clientChoose >= 0 && clientChoose < 19))
		{
			isCorrectChoose = false;
			do
			{
				cout << "Not valid choice, please type your choice: ";
				cin >> clientChoose;
				if (clientChoose >= 0 && clientChoose < 17)
					isCorrectChoose = true;
			} while (!isCorrectChoose);
		}
			makeAction(clientChoose, myHospital);


	} while (clientChoose != STOP);


	outFile << myHospital.getAllDepartments().size() << endl;

	for (i = 0; i < myHospital.getAllDepartments().size(); i++)
	{
		outFile << myHospital.getAllDepartments()[i]->getDepartmentName()<<endl;

		outFile << myHospital.getAllDepartments()[i]->getAllNurses().size() << endl;

			for (j = 0; j < myHospital.getAllDepartments()[i]->getAllNurses().size(); j++)
			{
				outFile << myHospital.getAllDepartments()[i]->getAllNurses()[j]->getEmployeeName() << endl;
				outFile << myHospital.getAllDepartments()[i]->getAllNurses()[j]->getNurseExp() << endl;

			}

		outFile << myHospital.getAllDepartments()[i]->getAllDoctors().size() << endl;

			for (j = 0; j < myHospital.getAllDepartments()[i]->getAllDoctors().size(); j++)
			{
				outFile << myHospital.getAllDepartments()[i]->getAllDoctors()[j]->getEmployeeName() << endl;
				outFile << myHospital.getAllDepartments()[i]->getAllDoctors()[j]->getDoctorSpeciality() << endl;
			}
		
	}

		outFile << myHospital.getReasearch()->getAllReasearchers().size()<<endl;
		for (i = 0; i < myHospital.getReasearch()->getAllReasearchers().size(); i++)
		{
			outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getEmployeeName() << endl;
			outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles().size() << endl;


			for (j = 0; j < myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles().size(); j++)
			{
				outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles()[j]->getArticleName() << endl;
				outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles()[j]->getMagzineName() << endl;
				outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles()[j]->getArticleDate().getDay() << endl;
				outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles()[j]->getArticleDate().getMonth() << endl;
				outFile << myHospital.getReasearch()->getAllReasearchers()[i]->getSllArticles()[j]->getArticleDate().getYear() << endl;
			}
		}

	outFile.close();
}
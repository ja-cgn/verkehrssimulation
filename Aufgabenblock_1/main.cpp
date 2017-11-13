#include <iostream>
#include <iomanip>
#include <vector>
#include "time.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#define EPSILON 0.01
#define TIME_INCREMENT 0.1
#define FUEL_UP_TIME 3

using namespace std;

//Global time var
double dGlobaleZeit = 0.0;

/*
	iRandom function creates a random integer value between the fed minumum and maximum value arguments.
*/
int iRandom(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

void vTemplateHeader()
{
	cout << "\n" << setw(10) << setiosflags(ios::left) << "TIME: " << dGlobaleZeit << resetiosflags(ios::right);
	cout << endl << setiosflags(ios::left) << setw(4) << "ID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(8) << "MaxKmh" << setw(16) << "GesamtStrecke" << setw(16)
		<< "Gesamtverbrauch" << setw(12) << "Tankinhalt" << resetiosflags(ios::right) << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vAufgabe_1()
{
	cout << "----------vAufgabe_1()----------" << endl;

	//MaxGeschwindigkeit in km/h -> 1 Stunde fahren = Geschwindigkeit Wert als Kilometer
	PKW f1("AUTO1", 200, 30, 90);
	PKW f2("AUTO2", 190, 34);
	PKW f3("AUTO3", 198.2, 29);
		
	for (; dGlobaleZeit <= 1; dGlobaleZeit += TIME_INCREMENT) // Double nie genau abfragen, die Toleranzgrenze ist durch += jedoch (sehr) groß und damit passend
	{
		//Output characteristics of vehicles
		vTemplateHeader();

		//Updating positions of vehicles
		f1.vAbfertigung();
		f2.vAbfertigung();
		f3.vAbfertigung();

		//Calling the output function 
		f1.vAusgabe();
		f2.vAusgabe();
		f3.vAusgabe();
	}
}

void vAufgabe_1_deb()
{
	cout << "----------vAufgabe_1_deb()----------" << endl;

	// Creating 4 vehicles
	Fahrzeug f4("AUTO1", 219.21);
	Fahrzeug f5("AUTO2", 202.99);
	Fahrzeug f6("AUTO3", 269.15);
	Fahrzeug f7("Auto4", 200.00);

	// Saving the vehicle pointers in an vector
	vector<Fahrzeug> feld_name(4);
	feld_name.push_back(f4);
	feld_name.push_back(f5);
	feld_name.push_back(f6);
	feld_name.push_back(f7);

	//printing the vector
	for (int i = 0; i <= 3; i++) 
	{
		feld_name[i].vAusgabe();
	}

/*	int a = 0;
	//setting one element as 0
	feld_name.insert(next(begin(feld_name)), f4); */

	feld_name.pop_back();
	//printing the vector again and use the debugger
	
	for (int i = 0; i <= 3; i++)
	{
		feld_name[i].vAusgabe();
	}

}

void vAufgabe_2()
{
	cout << "----------vAufgabe_2()----------" << endl;

	int iAnzahlPKW = 0;
	int iAnzahlFahrraeder = 0;
	vector<Fahrzeug*> vFahzeuge;
	vector<Fahrzeug*>::iterator fahrzeugIter = vFahzeuge.begin();

	//inputs from the user
	cout << "Wie viele PKWs sollen erzeugt werden?" << endl;
	cin >> iAnzahlPKW;
	cout << "Wie viele Fahrraeder sollen erzeugt werden?" << endl;
	cin >> iAnzahlFahrraeder;
	
	//Fahrrad fahr1("FAHR11", 20);


	//PKW Erzeugung
	for (int i = 1; i <= iAnzahlPKW; i++)
	{
		PKW* pkw = new PKW("AUTO" + to_string(i), iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));
		vFahzeuge.push_back(pkw);
	}

	//Fahrrad Erzeugung
	for (int i = 1; i <= iAnzahlFahrraeder; i++)
	{
		Fahrrad* fhrd = new Fahrrad("FHRD" + to_string(i), iRandom(12, 35)/1);
		vFahzeuge.push_back(fhrd);
	}

	//Hauptschleife
	for (; dGlobaleZeit <= 6; dGlobaleZeit += TIME_INCREMENT)
	{
		/*
			Fueling up the cars
		*/
		if (fabs(dGlobaleZeit - 3) <= EPSILON) //If Global Time = 3 hours => fuel up all the cars
		{
			fahrzeugIter = vFahzeuge.begin();
			while (fahrzeugIter != vFahzeuge.end())
			{
				(*fahrzeugIter)->dTanken();
				fahrzeugIter++;
			}
		}

		//Output characteristics of vehicles
		vTemplateHeader();

		//Updating positions of all vehicles
		fahrzeugIter = vFahzeuge.begin();
		while (fahrzeugIter != vFahzeuge.end())
		{
			(*fahrzeugIter)->vAbfertigung();
			fahrzeugIter++;
		}

		//Calling the output function 
		fahrzeugIter = vFahzeuge.begin();
		while (fahrzeugIter != vFahzeuge.end())
		{
			(*fahrzeugIter)->vAusgabe();
			fahrzeugIter++;
		}
	}
}

void vAufgabe_3()
{
	cout << "----------vAufgabe_3()----------" << endl;
	//PKW Erzeugung
	PKW pkw1("AUTO1", iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));
	PKW pkw2("AUTO2", iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));
	PKW pkw3("AUTO3", iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));

	//Fahrrad Erzeugung
	Fahrrad fhrd1("FHRD1", iRandom(12, 35));
	Fahrrad fhrd2("FHRD1", iRandom(12, 35));
	Fahrrad fhrd3("FHRD1", iRandom(12, 35));
	
	//Output the characteristics of vehicles
	vTemplateHeader();
	cout << pkw1 << pkw2 << pkw3 << fhrd1 << fhrd2 << fhrd3;
}

int main()
{
	//Feeding a time seed for the iRandom function
	srand(time(NULL));

	//vAufgabe_1(); 
    //vAufgabe_1_deb();
	//vAufgabe_2();
	vAufgabe_3();
}

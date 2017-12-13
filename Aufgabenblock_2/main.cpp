#include <iostream>
#include <iomanip>
#include <vector>
#include "time.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
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

void vTemplateHeaderFhzg()
{
	cout << "\n" << setw(10) << setiosflags(ios::left) << "TIME: " << dGlobaleZeit << resetiosflags(ios::right);
	cout << endl << setiosflags(ios::left) << setw(4) << "ID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(8) << "MaxKmh" << setw(16) << "GesamtStrecke" << setw(16)
		<< "Gesamtverbrauch" << setw(12) << "Tankinhalt" << resetiosflags(ios::right) << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vTemplateHeaderWeg()
{
	cout << endl << setiosflags(ios::left) << setw(4) << "ID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(8) << "Laenge" << setw(16) << "Fahrzeuge" << resetiosflags(ios::right) << endl;
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
		vTemplateHeaderFhzg();

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

	// Saving the vehicle pointers in an array
	Fahrzeug* feld_name[4];

	for (int i = 0; i < 4; i++)
	{
		PKW* fhzg = new PKW("FHZG" + to_string(i), iRandom(120, 290), 30);
		feld_name[i] = fhzg;
	}

	//printing the array
	for (int i = 0; i < 4; i++) 
	{
		feld_name[i]->vAusgabe();
		cout << endl;
	}
	
	//setting the 3rd vehicle to zero
	feld_name[2] = 0;

	for (int i = 0; i <= 3; i++)
	{
		feld_name[i]->vAusgabe();
		cout << endl;
	}

	/*
		The problem here is the setting of the 3rd element of the array to 0.
		Because the elements of the array are pointers to the vehicles, not vehicles themselves, this operation
		is equivalent to setting the pointer to a NULL pointer. Therefore the program crashes when it tries to
		brute force the NULL->vAusgabe() operation, which is not defined.
	*/
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

	//PKW Erzeugung
	for (int i = 1; i <= iAnzahlPKW; i++)
	{
		PKW* pkw = new PKW("AUTO" + to_string(i), iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));
		vFahzeuge.push_back(pkw);
	}

	//Fahrrad Erzeugung
	for (int i = 1; i <= iAnzahlFahrraeder; i++)
	{
		Fahrrad* fhrd = new Fahrrad("FHRD" + to_string(i), iRandom(12, 35));
		vFahzeuge.push_back(fhrd);
	}

	//Hauptschleife
	for (dGlobaleZeit = 0; dGlobaleZeit <= 6; dGlobaleZeit += TIME_INCREMENT)
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
		vTemplateHeaderFhzg();

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
	cout << "Die folgende Fahrzeuge waren erzeugt" << endl;
	vTemplateHeaderFhzg();
	cout << pkw1 << pkw2 << pkw3 << fhrd1 << fhrd2 << fhrd3;

	//Let the vehicles drive for a bit
	cout << "Lasse die Fahzeuge 2 Stunden lang fahren" << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 2; dGlobaleZeit += TIME_INCREMENT)
	{
		pkw1.vAbfertigung();
		pkw2.vAbfertigung();
		pkw3.vAbfertigung();
		fhrd1.vAbfertigung();
		fhrd2.vAbfertigung();
		fhrd3.vAbfertigung();
	}

	cout << "Gebe die Fahrzeug Info nach dem Fahrt aus" << endl;
	//Output vehicles after 2 hour drive
	vTemplateHeaderFhzg();
	cout << pkw1 << pkw2 << pkw3 << fhrd1 << fhrd2 << fhrd3;

	//Comparing the total distance
	cout << endl << "Vergleiche AUTO1 und AUTO3 um zu erfahren, wer eine laengere Strecke hintergelegt hat..." << endl;
	if (pkw1 < pkw3)
	{
		cout << "AUTO 3 ist weiter gefahren" << endl;
	}
	else if (pkw3 < pkw1)
	{
		cout << "AUTO1 ist weiter gefahren" << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
	
	cout << "\nErzeuge ein PKW" << endl;
	PKW* origpkw = new PKW("PKWtocopy", 300, 20, 40);
	cout << *origpkw << endl;
	cout << "Kopiere die Eigenschaften in einen neuen PKW" << endl;
	PKW* copypkw = new PKW(*origpkw);
	*copypkw = *origpkw;
	cout << *origpkw << *copypkw << endl;
}

void vAufgabe_4()
{
	vTemplateHeaderWeg();

	// Erzeuge einen Weg und gebe den aus
	Weg weg1("WEG1", 40);

	//Erzeuge zwei Fahrzeuge
	for (int i = 1; i <= 2; i++)
	{
		PKW* pkw = new PKW("AUTO" + to_string(i), iRandom(120, 290), iRandom(1, 30), iRandom(30, 90));
		weg1.vAnnahme(pkw);
	}

	//Gebe die Weg Informationen aus
	cout << weg1;

	//Fertige den Weg ab
	for (dGlobaleZeit = 0; dGlobaleZeit <= 2; dGlobaleZeit += TIME_INCREMENT)
	{
		weg1.vAbfertigung();
	}
}

/* Testing the exceptions implementation */
void vAufgabe_5()
{
	//Erzeuge einen Weg Instanz
	Weg weg("WEG1", 30);

	//Erzeuge Fahzeuge
	PKW fhzg1("AUDI", 210.1, 10, 120);
	PKW fhzg2("TESLA", 250.12, 4, 40);

	//Fuege die Fahrzeuge zu den Weg hinzu
	fhzg1.vNeueStrecke(&weg);
	fhzg2.vNeueStrecke(&weg);
	weg.vAnnahme(&fhzg1);
	weg.vAnnahme(&fhzg2);

	//Gebe den Weg Info aus
	cout << "Aktuelle Strecken: " << endl;
	vTemplateHeaderWeg();
	cout << weg;

	cout << "\nRufe vAbfertigung() auf...\n";
	//Fertige den Weg ab
	for (dGlobaleZeit = 0; dGlobaleZeit <= 2; dGlobaleZeit += TIME_INCREMENT)
	{
		//Fertige ab
		weg.vAbfertigung();

		//Gebe aus
		vTemplateHeaderFhzg();
		cout << fhzg1 << fhzg2;

	}
}

void vAufgabe_5_graf()
{
	//Weg Erzeugung
	Weg weg1("Hin", 50, Innenort);
	Weg weg2("Zurueck", 100, Landstrasse);

	//Fahzeug Erzeugung
	PKW pkw1("BMWi8", 250, 2.1);
	PKW pkw2("AUDIA4", 240, 6.5);

	//Fuege die Fahrzeuge hinzu
	weg1.vAnnahme(&pkw1);
	weg1.vAnnahme(&pkw2);
	weg2.vAnnahme(&pkw1);
	weg2.vAnnahme(&pkw2);
	
	//Init gragische Oberflaeche
	bInitialisiereGrafik(800, 500);
	int iStrassenKoor[] = {700, 250, 100, 250};
	bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), 500, 2, iStrassenKoor);

	//Hauptschleife
	for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += TIME_INCREMENT)
	{
		pkw1.vZeichnen(&weg1);
		//pkw1.vZeichnen(&weg2);
		//pkw2.vZeichnen(&weg1);
		//pkw2.vZeichnen(&weg2);

		vSetzeZeit(dGlobaleZeit);
		vSleep(500);
		
		//Fertige ab
		weg1.vAbfertigung();
		weg2.vAbfertigung();

		//Debug console
		vTemplateHeaderFhzg();
		cout << pkw1 << pkw2;
	}

	bLoescheFahrzeug(pkw1.sGetName());
	bLoescheFahrzeug(pkw2.sGetName());
}

int main()
{
	//Feeding a time seed for the iRandom function
	srand(time(NULL));
	string sInput = "";

	while (sInput != "-1")
	{
		cout << "Welche Funktion moechten Sie aufrufen?" << endl;
		cout << "1 - vAufgabe_1_deb()\n2 - vAufgabe_2\n";
		cout << "3 - vAufgabe_3()\n4 - vAufgabe_4()\n";
		cout << "5 - vAufgabe_5()\n51 - vAufgabe_5_graf()\n-1 - exit\nIhre Eingabe: ";
		cin >> sInput;

		if (sInput == "1")
		{
			vAufgabe_1_deb();
		}
		else if (sInput == "2")
		{
			vAufgabe_2();
		}
		else if (sInput == "3")
		{
			vAufgabe_3();
		}
		else if (sInput == "4")
		{
			vAufgabe_4();
		}
		else if (sInput == "5")
		{
			vAufgabe_5();
		}
		else if (sInput == "51")
		{
			vAufgabe_5_graf();
		}
		else
		{
			cout << "Falsche Eingabe. Probieren Sie noch mal" << endl;
		}
	}
}

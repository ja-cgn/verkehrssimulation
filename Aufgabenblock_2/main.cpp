#include <iostream>
#include <iomanip>
#include <vector>
#include "time.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "LazyAktion.h"
#define EPSILON 0.01
#define TIME_INCREMENT 0.1
#define FUEL_UP_TIME 3

using namespace std;

//Global time var
double dGlobaleZeit = 0.0;

/*
	iRandom function creates a random integer value between the fed minumum and maximum value arguments.
*/
int iRandom(int min = 1, int max = 10)
{
	return min + (rand() % (max - min + 1));
}

void vTemplateHeaderFhzg()
{	

	cout << resetiosflags(ios::right) << setw(10) << setiosflags(ios::left) << "TIME: " << dGlobaleZeit;
	cout << endl << setiosflags(ios::left) << setw(4) << "ID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(8) << "MaxKmh" << setw(16) << "GesamtStrecke" << setw(16)
		<< "Gesamtverbrauch" << setw(12) << "Tankinhalt" << resetiosflags(ios::right) << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vTemplateHeaderWeg()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << "ID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
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
	cout << "----------vAufgabe_4()----------" << endl;
	// Erzeuge einen Weg
	Weg weg1("WEG1", 100);

	//Erzeuge zwei Fahrzeuge
	PKW pkw("SLSAMG", 317, 13, 85);
	Fahrrad fhrd("BIKE", 12);

	weg1.vAnnahme(&pkw);
	weg1.vAnnahme(&fhrd);

	//Fertige den Weg ab
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += TIME_INCREMENT)
	{
		weg1.vAbfertigung();
		vTemplateHeaderFhzg();
		cout << pkw << fhrd;
		vTemplateHeaderWeg();
		cout << weg1;
	}
}

/* Testing the exceptions implementation */
void vAufgabe_5()
{
	cout << "----------vAufgabe_5()----------" << endl;
	//Erzeuge einen Weg Instanz
	Weg weg("WEG1", 250, Landstrasse);

	//Erzeuge Fahzeuge
	PKW fhzg1("AUDI", 210.1, 10, 120);
	PKW fhzg2("TESLA", 212.12, 4, 40);

	//Fuege die Fahrzeuge zu den Weg hinzu
	weg.vAnnahme(&fhzg1);
	weg.vAnnahme(&fhzg2, 3.0);

	cout << "\nRufe vAbfertigung() auf...\n";
	//Fertige den Weg ab
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += TIME_INCREMENT)
	{
		//Fertige ab
		weg.vAbfertigung();

		//Gebe die Fahzeuge aus
		vTemplateHeaderFhzg();
		cout << fhzg1 << fhzg2;
		vTemplateHeaderWeg();
		cout << weg;
	}
}

void vAufgabe_5_graf()
{
	cout << "----------vAufgabe_5_graf()----------" << endl;
	//Zwei Wege laenge 500
	Weg weg1("Hin", 500, Landstrasse);
	Weg weg2("Zurueck", 500, Landstrasse);

	//Fahzeug Erzeugung
	PKW pkw1("BMWi8", 250, 2.1, 30);
	PKW pkw2("AUDIA4", 240, 6.5, 58);
	PKW pkw3("FOCUS", 137, 5.3, 62);
	Fahrrad fhrd("BIKE", 18);

	//Fuege die Fahrzeuge hinzu
	weg1.vAnnahme(&pkw1);
	weg1.vAnnahme(&pkw2, 3.0);
	weg2.vAnnahme(&pkw3);
	weg2.vAnnahme(&fhrd, 2.5);
	
	//Init gragische Oberflaeche
	bInitialisiereGrafik(800, 500);
	int iStrassenKoor[] = {700, 250, 100, 250};
	bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), 500, 2, iStrassenKoor);

	//Hauptschleife
	for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += TIME_INCREMENT)
	{
		vSetzeZeit(dGlobaleZeit);
		vSleep(500);
		
		//Fertige ab
		weg1.vAbfertigung();
		weg2.vAbfertigung();

		//Zeichne die neue Positionen
		pkw1.vZeichnen(&weg1);
		pkw2.vZeichnen(&weg1);
		pkw3.vZeichnen(&weg2);
		fhrd.vZeichnen(&weg2);

		//Debug console
		vTemplateHeaderFhzg();
		cout << pkw1 << pkw2 << pkw3 << fhrd;
		vTemplateHeaderWeg();
		cout << weg1 << weg2;
	}

	bLoescheFahrzeug(pkw1.sGetName());
	bLoescheFahrzeug(pkw2.sGetName());
	bLoescheFahrzeug(pkw3.sGetName());
	bLoescheFahrzeug(fhrd.sGetName());
}

void vAufgabe_6()
{
	cout << "----------vAufgabe_6()----------" << endl;

	//Zwei Wege laenge 500
	Weg weg1("Hin", 500, Innenort);
	Weg weg2("Zurueck", 500, Innenort);

	//Fahzeug Erzeugung
	PKW pkw1("BMWi8", 250, 2.1, 30);
	PKW pkw2("AUDIA4", 240, 6.5, 58);
	PKW pkw3("FOCUS", 137, 5.3, 62);
	Fahrrad fhrd("BIKE", 18);

	//Fuege die Fahrzeuge hinzu
	weg1.vAnnahme(&pkw1);
	weg2.vAnnahme(&pkw2, 3.0);
	weg1.vAnnahme(&pkw3);
	weg2.vAnnahme(&fhrd, 2.5);

	//Init gragische Oberflaeche
	bInitialisiereGrafik(800, 500);
	int iStrassenKoor[] = { 700, 250, 100, 250 };
	bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), 500, 2, iStrassenKoor);

	//Hauptschleife
	for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += TIME_INCREMENT)
	{
		vSetzeZeit(dGlobaleZeit);
		vSleep(1);

		//Fertige ab
		weg1.vAbfertigung();
		weg2.vAbfertigung();

		//Zeichne die neue Positionen
		pkw1.vZeichnen(&weg1);
		pkw2.vZeichnen(&weg2);
		pkw3.vZeichnen(&weg1);
		fhrd.vZeichnen(&weg2);

		//Debug console
		vTemplateHeaderFhzg();
		cout << pkw1 << pkw2 << pkw3 << fhrd;
		vTemplateHeaderWeg();
		cout << weg1 << weg2;
	}

	bLoescheFahrzeug(pkw1.sGetName());
	bLoescheFahrzeug(pkw2.sGetName());
	bLoescheFahrzeug(pkw3.sGetName());
	bLoescheFahrzeug(fhrd.sGetName());
}

/* Testing Lazy Liste implementation */
void vAufgabe_6a()
{
	cout << "----------vAufgabe_6a()----------" << endl;
	cout << "=== Teste die Implementation von Lazy Liste... ===" << endl;
	LazyListe<int>* lazyList = new LazyListe<int>();
	LazyListe<int>::iterator lazyListIter = lazyList->begin();


	cout << "Fuege zufaellige int Objekte hinzu" << endl;
	for (int i = 1; i <= 10; i++)
	{
		lazyList->push_back(int(iRandom()));
	}

	//Uebertrage die Aenderungen
	lazyList->vAktualisieren();

	//Gebe die Liste aus
	cout << "\nDie Liste ist fertig: " << endl;
	lazyListIter = lazyList->begin();
	while (lazyListIter != lazyList->end())
	{
		cout << *lazyListIter << endl;
		lazyListIter++;
	}

	cout << "\nLoesche alle Elemente > 5" << endl;
	lazyListIter = lazyList->begin();
	while (lazyListIter != lazyList->end())
	{
		if (*lazyListIter > 5)
		{
			lazyList->erase(lazyListIter);
		}

		lazyListIter++;
	}

	//Gebe die Liste aus ohne Aktualisierung
	cout << "\nDie Ausgabe ohne Aktualisierung: " << endl;
	lazyListIter = lazyList->begin();
	while (lazyListIter != lazyList->end())
	{
		cout << *lazyListIter << endl;
		lazyListIter++;
	}

	//Uebertrage die Aenderungen
	lazyList->vAktualisieren();

	//Gebe die Liste nach eine Aktualisierung
	cout << "\nDie Ausgabe nach der Aktualisierung: " << endl;
	lazyListIter = lazyList->begin();
	while (lazyListIter != lazyList->end())
	{
		cout << *lazyListIter << endl;
		lazyListIter++;
	}

	//Fuege am Anfang und am Ende der Liste noch zwei Zahlen
	lazyList->push_back(iRandom());
	lazyList->push_front(iRandom());

	//Uebertrage die Aenderungen
	lazyList->vAktualisieren();

	//Gebe die Liste aus ohne Aktualisierung
	cout << "\nDie Ausgabe nach dem Hinzufuegen von zwei belibigen Zahlen am Anfang und am Ende: " << endl;
	lazyListIter = lazyList->begin();
	while (lazyListIter != lazyList->end())
	{
		cout << *lazyListIter << endl;
		lazyListIter++;
	}
}

int main()
{
	//Feeding a time seed for the iRandom function
	srand(time(NULL));
	string iInput = 0;

	while (iInput != "-1")
	{	
		cout << "Welche Funktion moechten Sie aufrufen?" << endl;
		cout << "1 - vAufgabe_1_deb()\n2 - vAufgabe_2\n";
		cout << "3 - vAufgabe_3()\n4 - vAufgabe_4()\n";
		cout << "5 - vAufgabe_5()\n51 - vAufgabe_5_graf()\n";
		cout << "6 - vAufgabe_6()\n61 - vAufgabe_6a()";
		cout << "\n-1 - exit\nIhre Eingabe: ";
		cin >> iInput;

		switch (iInput)
		{
		case "1": 
		default:
			break;
		}

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
		else if (sInput == "6")
		{
			vAufgabe_6();
		}
		else if (sInput == "61")
		{
			vAufgabe_6a();
		}
		else if (sInput == "-1")
		{
			cout << "Exiting..." << endl;
		}
		else
		{
			cout << "Falsche Eingabe. Probieren Sie noch mal" << endl;
		}
	}
}

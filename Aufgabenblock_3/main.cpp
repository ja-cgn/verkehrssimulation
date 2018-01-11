#include <iostream>
#include <iomanip>
#include <vector>
#include "AktivesVO.h"
#include "time.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "LazyAktion.h"
#include "Kreuzung.h"
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
	Weg weg1("Hin", 500);
	Weg weg2("Zurueck", 500);

	//Fahzeug Erzeugung
	PKW pkw1("BMWi8", 299, 2.1, 30);
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

void vAufgabe_7()
{
	cout << "----------vAufgabe_7()----------" << endl;
	
	//Zwei Wege laenge 500
	Weg weg1("Hin", 500, Autobahn, true);
	Weg weg2("Zurueck", 500, Autobahn, true);

	//Graphische Oberflaeche
	bInitialisiereGrafik(800, 500);
	int iStrassenKoor[] = { 700, 250, 100, 250 };
	bZeichneStrasse(weg1.sGetName(), weg2.sGetName(), 500, 2, iStrassenKoor);

	//Erzeuge ein PKW und ein Fahrrad
	PKW pkw1("FOCUS", 67, 5.3, 62);
	PKW pkw2("AUDIA4", 240, 6.5, 58);
	Fahrrad fhrd("BIKE", 23);
	
	weg1.vAnnahme(&pkw1, 0.8);
	weg1.vAnnahme(&fhrd, 0.9);
	weg1.vAnnahme(&pkw2, 1.6);

	int max = 10;
	//Hauptschleife
	for (dGlobaleZeit = 0; dGlobaleZeit <= max; dGlobaleZeit += TIME_INCREMENT)
	{
		vSetzeZeit(dGlobaleZeit);
		vSleep(500);

		//Nach der haelfte der Zeit ein weiterer parkender PKW annehmen
		if (dGlobaleZeit == floor(max / 2))
		{
			weg1.vAnnahme(&pkw2, max/2 + TIME_INCREMENT);
		}

		//Fertige ab und zeichne
		weg1.vAbfertigung();
		weg2.vAbfertigung();

		//Debug console
		vTemplateHeaderFhzg();
		cout << pkw1 << pkw2 << fhrd;
		vTemplateHeaderWeg();
		cout << weg1;
	}
}

void vAufgabe_8()
{
	cout << "----------vAufgabe_8()----------" << endl;

	//Erzeuge ein PKW und ein Fahrrad
	PKW pkw1("FOCUS", 137, 5.3, 62);
	PKW pkw2("AUDIA4", 240, 6.5, 58);
	Fahrrad fhrd("BIKE", 23);

	//Graphische Initialisierungen
	bInitialisiereGrafik(1200, 800);
	Kreuzung Kreuzung1("Kr1");
	Kreuzung Kreuzung2("Kr2", 1000);
	Kreuzung Kreuzung3("Kr3");
	Kreuzung Kreuzung4("Kr4");

	Kreuzung1.vVerbinde("Strasse1_s", "Strasse1_n", 40, &Kreuzung2, Innenort);
	Kreuzung2.vVerbinde("Strasse2_s", "Strasse2_n", 115, &Kreuzung3, Autobahn, false);
	Kreuzung2.vVerbinde("Strasse3_s", "Strasse3_n", 40, &Kreuzung3, Innenort);
	Kreuzung2.vVerbinde("Strasse4_w", "Strasse4_e", 55, &Kreuzung4, Innenort);
	Kreuzung3.vVerbinde("Strasse5_w", "Strasse5_e", 85, &Kreuzung4, Autobahn, false);
	Kreuzung4.vVerbinde("Strasse6_w", "Strasse6_e", 130, &Kreuzung4, Landstrasse, false);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	int strasse1[] = { 680, 40, 680, 300 };
	int strasse2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int strasse3[] = { 680, 300, 680, 570 };
	int strasse4[] = { 680, 300, 320, 300 };
	int strasse5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int strasse6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };
	bZeichneStrasse("Strasse1_s", "Strasse1_n", 40, 2, strasse1);
	bZeichneStrasse("Strasse2_s", "Strasse2_n", 115, 6, strasse2);
	bZeichneStrasse("Strasse3_s", "Strasse3_n", 40, 2, strasse3);
	bZeichneStrasse("Strasse4_w", "Strasse4_e", 55, 2, strasse4);
	bZeichneStrasse("Strasse5_w", "Strasse5_e", 85, 5, strasse5);
	bZeichneStrasse("Strasse6_w", "Strasse6_e", 130, 7, strasse6);

	Kreuzung1.vAnnahme(&pkw1, 0);
	
	for (dGlobaleZeit = 0; dGlobaleZeit <= 25; dGlobaleZeit += TIME_INCREMENT)
	{
		vSetzeZeit(dGlobaleZeit);
		vSleep(500);

		//Fertige ab
		Kreuzung1.vAbfertigung();

		//Zeichne die neue Positionen
		/*
		pkw1.vZeichnen(&weg1);
		pkw2.vZeichnen(&weg1);
		fhrd.vZeichnen(&weg1);
		*/
		//Debug console
		vTemplateHeaderFhzg();
		cout << pkw1 << pkw2 << fhrd;
		vTemplateHeaderWeg();
		//cout << weg1;
	}
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
		cout << "5 - vAufgabe_5()\n51 - vAufgabe_5_graf()\n";
		cout << "6 - vAufgabe_6()\n61 - vAufgabe_6a()\n";
		cout << "7 - vAufgabe_7()\n8 - vAufgabe_8()";
		cout << "\n-1 - exit\nIhre Eingabe: ";
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
		else if (sInput == "6")
		{
			vAufgabe_6();
		}
		else if (sInput == "61")
		{
			vAufgabe_6a();
		}
		else if (sInput == "7")
		{
			vAufgabe_7();
		}
		else if (sInput == "8")
		{
			vAufgabe_8();
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

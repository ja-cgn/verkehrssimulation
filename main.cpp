#include <iostream>
#include <iomanip>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#define TIME_INCREMENT 0.1

using namespace std;

//Global time var
double dGlobaleZeit = 0.0;

void vAufgabe_1()
{
	//MaxGeschwindigkeit in km/h -> 1 Stunde fahren = Geschwindigkeit Wert als Kilometer
	PKW f1("AUTO1", 200, 30, 90);
	PKW f2("AUTO2", 190, 34);
	PKW f3("AUTO3", 198.2, 29);
		
	for (; dGlobaleZeit <= 1; dGlobaleZeit += TIME_INCREMENT) // Double nie genau abfragen, die Toleranzgrenze ist durch += jedoch (sehr) groß und damit passend
	{
		//Output characteristics of vehicles
		cout << setiosflags(ios::left) << setw(4) << "\nID" << setw(7) << "Name" << ":" << resetiosflags(ios::left)
			 << setiosflags(ios::right) << setw(8) << "MaxKmh" << setw(16) << "GesamtStrecke" << setw(16) 
			 << "Gesamtverbrauch" << setw(12) << "Tankinhalt" << resetiosflags(ios::right) << endl;

		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

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
	//TODO

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

int main()
{
	vAufgabe_1(); 
    //vAufgabe_1_deb();
}

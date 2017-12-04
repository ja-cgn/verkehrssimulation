#include "Weg.h"
#include <iostream>
#include <list>
#include "Fahrzeug.h"

list<Fahrzeug*>::iterator FahrzeugeListIter;

Weg::Weg()
	:AktivesVO()
{
}

Weg::Weg(string sName, double dLaenge, Begrenzung eTempolimit)
	:AktivesVO(sName)
{
}

Weg::~Weg()
{
}

void Weg::vAbfertigung()
{
	//alle auf dem Weg befindlichen Fahzeuge abfertigen
	FahrzeugeListIter = (this->p_pFahrzeuge).begin();
	while (FahrzeugeListIter != p_pFahrzeuge.end())
	{
		(*FahrzeugeListIter)->vAbfertigung();
	}
}

void Weg::ostreamAusgabe(ostream & output)
{
	//Call the Abstract parent class output
	AktivesVO::ostreamAusgabe(output);

	//Output unique parameters
	output << ":";
	output.flags(ios::right);
	output.width(8);
	output << this->p_dLaenge;
	cout << endl;
}

double Weg::dGetLaenge()
{
	return this->p_dLaenge;
}

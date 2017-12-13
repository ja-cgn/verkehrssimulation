#include "Weg.h"
#include <iostream>
#include <list>
#include "Fahrzeug.h"
#include "FahrAusnahme.h"

LazyListe<Fahrzeug*>::iterator FahrzeugeListIter;

Weg::Weg()
	:AktivesVO()
{
}

Weg::Weg(string sName, double dLaenge, Begrenzung eTempolimit)
	:AktivesVO(sName), p_dLaenge(dLaenge), p_eLimit(eTempolimit)
{
}

Weg::~Weg()
{
}

void Weg::vAbfertigung()
{
	//Aktualisiere die Lazy Liste um die Aenderungen zu uebertragen
	this->p_pFahrzeuge.vAktualisieren();
	//alle auf dem Weg befindlichen Fahzeuge abfertigen
	for (LazyListe<Fahrzeug*>::iterator iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++)
	{
		//Exception handling
		try
		{
			(*iter)->vAbfertigung();
		}
		catch (FahrAusnahme& exception)
		{
			exception.vBearbeiten();
		}
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
	output.width(10);
	output << "( ";

	//Output all the vehicles on the road
	FahrzeugeListIter = (this->p_pFahrzeuge).begin();
	while (FahrzeugeListIter != p_pFahrzeuge.end())
	{
		output << (*FahrzeugeListIter)->sGetName();
		output << " ";

		FahrzeugeListIter++;
	}

	output << " )";
	cout << endl;
}

/* FzgFahren */
void Weg::vAnnahme(Fahrzeug * fhzg)
{
	//Bei jeder Annahme soll vNeueStrecke() aufgerufen werden
	fhzg->vNeueStrecke(this);

	//Nehme das Fahrzeug an
	(this->p_pFahrzeuge).push_back(fhzg);
}

/* FzgParken */
void Weg::vAnnahme(Fahrzeug * fhzg, double dStartZeit)
{
	//Bei jeder Annahme soll vNeueStrecke() aufgerufen werden
	fhzg->vNeueStrecke(this, dStartZeit);

	//Nehme das Fahrzeug an
	(this->p_pFahrzeuge).push_front(fhzg);
}

void Weg::vAbgabe(Fahrzeug * fhzg)
{
	//Nur ausfuehren wenn die Liste nicht leer ist
	if (!this->p_pFahrzeuge.empty())
	{
		FahrzeugeListIter = this->p_pFahrzeuge.begin();
		while (FahrzeugeListIter != this->p_pFahrzeuge.end())
		{
			//loesche das Fahrzeug, bei dem die Ausnahme aufgetreten ist 
			if (*FahrzeugeListIter == fhzg)
			{
				p_pFahrzeuge.erase(FahrzeugeListIter);
			}

			FahrzeugeListIter++;
		}
	}
}

double Weg::dGetLaenge()
{
	return this->p_dLaenge;
}

double Weg::dGetLimit()
{
	return this->p_eLimit;
}

LazyListe<Fahrzeug*> Weg::getFahrzeuge()
{
	return this->p_pFahrzeuge;
}

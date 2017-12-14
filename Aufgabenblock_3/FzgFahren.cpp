#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Streckenende.h"

FzgFahren::FzgFahren()
	:FzgVerhalten()
{
}

FzgFahren::FzgFahren(Weg * weg)
	:FzgVerhalten(weg)
{
}


FzgFahren::~FzgFahren()
{
}


/* Erfahre wie weit ein Fahrzeug innerhalb des übergebenen Zeitraums noch fahren kann*/
double FzgFahren::dStrecke(Fahrzeug * fhzg, double dTimeInterval)
{
	//Speichere die Laenge des Weges
	double dWegLaenge = this->getWeg()->dGetLaenge();
	//Speichere max Fahrbare Strecke
	double dMaxFahr = fhzg->dGeschwindigkeit()*dTimeInterval;

	//Streckende Ausnahme
	if (fabs(fhzg->dGetAbschnittStrecke() - dWegLaenge) < EPSILON)
	{
		throw Streckenende(fhzg, this->getWeg());
	}
	// Wenn max Fahrbare Strecke groesser als uebrig gebliebene Strecke
	if (fhzg->dGetAbschnittStrecke() + dMaxFahr > dWegLaenge)
	{
		return dWegLaenge - fhzg->dGetAbschnittStrecke();
	}
	else
	{
		return dMaxFahr;
	}
}

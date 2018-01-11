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

	if (fhzg->dGetAbschnittStrecke() + dMaxFahr > this->getWeg()->dGetVirtSchranke() && this->p_pAktuellerWeg->dGetVirtSchranke() != -1)
	{
		return this->getWeg()->dGetVirtSchranke() - fhzg->dGetAbschnittStrecke();
	}
	else
	{
		this->p_pAktuellerWeg->vSetVirtSchranke(fhzg->dGetAbschnittStrecke() + dMaxFahr);
		return dMaxFahr;
	}
	
}

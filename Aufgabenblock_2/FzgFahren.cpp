#include "FzgFahren.h"
#include "Fahrzeug.h"
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
	//Max Strecke abhaengig von dem Weg
	double dMaxStrecke = this->p_pAktuellerWeg->dGetLaenge();

	//Berechne fahrbare Strecke in diesem Zeitraum
	double dFahrbareStrecke = fhzg->dGeschwindigkeit() * dTimeInterval;
	double dNeueGesamtStrecke = fhzg->dGetGesamtStrecke() + dFahrbareStrecke;

	//Wenn fahrbare Strecke > max uebrige Strecke => berechne max fahrbare Strecke
	//Doubles um Epsilon testen
	if ((dNeueGesamtStrecke - dMaxStrecke) > EPSILON)
	{
		if (fabs(fhzg->dGetGesamtStrecke() - dMaxStrecke) < EPSILON)
		{
			throw Streckenende(fhzg, this->p_pAktuellerWeg);
		}
		else
		{
			return dFahrbareStrecke - (dNeueGesamtStrecke - dMaxStrecke);
		}
	}
	else
	{
		return dFahrbareStrecke;
	}
}

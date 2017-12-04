#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg)
	:p_pAktuellerWeg(weg)
{
}

FzgVerhalten::~FzgVerhalten()
{
}

/* Erfahre wie weit ein Fahrzeug innerhalb des übergebenen Zeitraums noch fahren kann*/
double FzgVerhalten::dStrecke(Fahrzeug * fhzg, double dTimeInterval)
{
	//Max Strecke abhaengig von dem Weg
	double dMaxStrecke = (this->p_pAktuellerWeg)->dGetLaenge();

	//Berechne fahrbare Strecke in diesem Zeitraum
	double dFahrbareStrecke = fhzg->dGeschwindigkeit() * dTimeInterval;
	double dNeueGesamtStrecke = fhzg->dGetGesamtStrecke() + dFahrbareStrecke;

	//Wenn fahrbare Strecke > max uebrige Strecke => berechne max fahrbare Strecke
	//Doubles um Epsilon testen
	if ((dNeueGesamtStrecke - dMaxStrecke) > EPSILON)
	{
		return dFahrbareStrecke - (dNeueGesamtStrecke - dMaxStrecke);
	}
	else
	{
		return dFahrbareStrecke;
	}
}

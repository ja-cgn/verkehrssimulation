#pragma once
#include "AktivesVO.h"
#include <list>
class Fahrzeug;

enum Begrenzung
{
	Innenort = 50,
	Landstrasse = 100,
	Autobahn = -1
};

class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eTempolimit = Autobahn);
	~Weg();

	double dGetLaenge();
	double dGetLimit();
	list<Fahrzeug*> getFahrzeuge();

	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	virtual void vAnnahme(Fahrzeug* fhzg); //fahrendes Fahrzeug
	virtual void vAnnahme(Fahrzeug* fhzg, double dStartZeit); //parkendes Fahrzeug

private:
	double p_dLaenge;
	list<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;

protected:

};


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

	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	
private:
	double p_dLaenge;
	list<Fahrzeug*> p_pFahrzeuge;
	static Begrenzung p_eLimit;

protected:

};


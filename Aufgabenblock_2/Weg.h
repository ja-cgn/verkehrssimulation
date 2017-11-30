#pragma once
#include "AktivesVO.h"
#include "Fahrzeug.h"
#include <list>

typedef list<Fahrzeug*> FahrzeugeList;
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
	Weg(string sName, double dLaenge, Begrenzung eTempolimit);
	~Weg();

	void vAbfertigung();

private:
	double p_dLaenge;
	FahrzeugeList p_pFahrzeuge;
	static Begrenzung p_eLimit;

protected:

};


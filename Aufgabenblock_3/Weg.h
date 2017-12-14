#pragma once
#include "AktivesVO.h"
#include "LazyAktion.h"
#include "LazyListe.h"
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
	//Constructors & Destructor
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eTempolimit = Autobahn);
	~Weg();

	//Getter functions
	double dGetLaenge();
	double dGetLimit();
	LazyListe<Fahrzeug*> getFahrzeuge();

	//Methods
	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	virtual void vAnnahme(Fahrzeug* fhzg); //fahrendes Fahrzeug
	virtual void vAnnahme(Fahrzeug* fhzg, double dStartZeit); //parkendes Fahrzeug
	virtual void vAbgabe(Fahrzeug* fhzg);

private:
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;

protected:

};


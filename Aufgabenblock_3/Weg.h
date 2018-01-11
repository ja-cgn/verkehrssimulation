#pragma once
#include "AktivesVO.h"
#include "LazyAktion.h"
#include "LazyListe.h"
class Fahrzeug;
class Kreuzung;

class Weg :
	public AktivesVO
{
public:
	//Constructors & Destructor
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eTempolimit = Autobahn, bool bUeverbot = true);
	~Weg();

	//Getter functions
	double dGetLaenge();
	double dGetLimit();
	double dGetVirtSchranke();
	LazyListe<Fahrzeug*> getFahrzeuge();
	bool bGetVerbot();
	Kreuzung* getZiel();
	Weg* getRueckweg();

	//Setter functions
	void vSetVirtSchranke(double dSchranke);

	//Methods
	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	virtual void vVerbinde(Weg* rueckweg, Kreuzung* ziel);
	virtual void vAnnahme(Fahrzeug* fhzg); //fahrendes Fahrzeug
	virtual void vAnnahme(Fahrzeug* fhzg, double dStartZeit); //parkendes Fahrzeug
	virtual void vAbgabe(Fahrzeug* fhzg);

private:
	double p_dLaenge;
	double p_dVirtSchranke;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Weg* p_pRueckweg;
	Kreuzung* p_pZiel;
	Begrenzung p_eLimit;
	bool p_bUeberholverbot;

protected:

};


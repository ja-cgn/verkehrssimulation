#pragma once
#include "AktivesVO.h"
#include "LazyListe.h"
#include <list>
class Fahrzeug;
class Weg;

using namespace std;

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string sName, double dTankvolumen = 0);
	~Kreuzung();

	//Methods
	void vVerbinde(string sWeg1, string sWeg2, double dLaenge, Kreuzung* ziel, Begrenzung eLimit = Autobahn, bool bVerbot = true);
	void vTanken(Fahrzeug* fhzg);
	void vAnnahme(Fahrzeug* fhzg, double dStartzeit);
	void vAnnahme(Weg* weg);
	void vAbfertigung();

private:
	list<Weg*> p_pWegListe;
	double p_dTankstelle;
};


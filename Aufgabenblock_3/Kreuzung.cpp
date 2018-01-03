#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "Weg.h"

Kreuzung::Kreuzung()
{
}


Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(string sWeg1, string sWeg2, double dLaenge, Kreuzung * ziel, Begrenzung eLimit, bool bVerbot)
{
	//Erzeuge Wege
	Weg* hin = new Weg(sWeg1, dLaenge, eLimit, bVerbot);
	Weg* rueck = new Weg(sWeg2, dLaenge, eLimit, bVerbot);

	//Verbinde
	hin->vVerbinde(rueck, ziel);
	rueck->vVerbinde(hin, this);

	//Wege in Kreuzungen speichern
	p_pWegListe.push_back(hin);
	ziel->vAnnahme(rueck);
	
}

void Kreuzung::vTanken(Fahrzeug * fhzg)
{
	if (this->p_dTankstelle > EPSILON)
	{
		p_dTankstelle -= fhzg->dTanken();
	}
}

void Kreuzung::vAnnahme(Fahrzeug * fhzg, double dStartzeit)
{
}

void Kreuzung::vAnnahme(Weg * weg)
{
	this->p_pWegListe.push_back(weg);
}

void Kreuzung::vAbfertigung()
{
}

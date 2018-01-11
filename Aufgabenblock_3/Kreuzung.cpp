#include "Kreuzung.h"
#include "SimuClient.h"
#include "Fahrzeug.h"
#include "Weg.h"

list<Weg*>::iterator WeglistIter;

Kreuzung::Kreuzung()
	:AktivesVO()
{
}

Kreuzung::Kreuzung(string sName, double dTankvolumen)
	:AktivesVO(sName), p_dTankstelle(dTankvolumen)
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
	if (!p_pWegListe.empty())
	{
		this->vTanken(fhzg);
		p_pWegListe.front()->vAnnahme(fhzg, dStartzeit);
	}
}

void Kreuzung::vAnnahme(Weg * weg)
{
	this->p_pWegListe.push_back(weg);
}

void Kreuzung::vAbfertigung()
{
	WeglistIter = p_pWegListe.begin();
	if (!p_pWegListe.empty())
	{
		while (WeglistIter != p_pWegListe.end())
		{
			(*WeglistIter)->vAbfertigung();

			WeglistIter++;
		}
	}
}

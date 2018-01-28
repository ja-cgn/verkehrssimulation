#include "Kreuzung.h"
#include "SimuClient.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>
#include <iomanip>

vector<Weg*>::iterator WeglistIter;

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

void Kreuzung::vZeichnen()
{
	WeglistIter = p_pWegListe.begin();

	while (WeglistIter != p_pWegListe.end())
	{
		(*WeglistIter)->vZeichnen();

		WeglistIter++;
	}
}

void Kreuzung::ostreamAusgabe(ostream & output)
{
	//Call the Abstract parent class output
	AktivesVO::ostreamAusgabe(output);

	//Output unique parameters
	output << ":";
	output.flags(ios::right);
	output.width(8);

	//Output all the roads leading to the intersection
	WeglistIter = p_pWegListe.begin();
	if (!p_pWegListe.empty())
	{
		while (WeglistIter != p_pWegListe.end())
		{
			output << (*WeglistIter)->sGetName();
			output << " ";
			WeglistIter++;
		}
	}
	cout << endl;
}

istream & Kreuzung::istreamEingabe(istream & input)
{
	//Call the Abstract parent class input
	AktivesVO::istreamEingabe(input);

	//Input the unique parameters
	input >> p_dTankstelle;
	return input;
}

/* Leitet das Fahrzeug auf eine neue Kreuzung weiter */
void Kreuzung::vWeiterleiten(Fahrzeug * fhzg, Weg * origin)
{	
	Weg* destination = this->ptZufaelligerWeg(origin->getRueckweg());
	this->vTanken(fhzg);
	destination->vAnnahme(fhzg);

	//Umsetzung outputs
	cout << "\nSETZE DAS FAHRZEUG UM! vWeiterleiten() wurde aufgerufen!\n";
	cout << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << "ZEIT" << ":" << dGlobaleZeit << endl
		<< setw(10) << "KREUZUNG" << ":" << this->sGetName() << endl
		<< setw(10) << "WECHSEL" << ":" << origin->sGetName() << "->" << destination->sGetName() << endl
		<< setw(10) << "FAHRZEUG" << ":" << *fhzg << endl;
}

/* Liefert eine zufaellige Zielkreuzung */
Weg* Kreuzung::ptZufaelligerWeg(Weg* origin)
{
	int WeglistLength = p_pWegListe.size();
	
	if (!p_pWegListe.empty())
	{
		if (WeglistLength == 1)
		{
			return p_pWegListe[0];
		}
		else
		{
			while (1)
			{
				int iRandWegNum = rand() % WeglistLength;
				Weg* destination = p_pWegListe[iRandWegNum];
				if (destination != origin)
				{
					return destination;
				}
			}
		}
	}
	else
	{
		return nullptr;
	}
	
}

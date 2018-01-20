#include "Welt.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <sstream>

const string Welt::KREUZUNGTAG = "KREUZUNG";
const string Welt::STRASSETAG = "STRASSE";
const string Welt::PKWTAG = "PKW";
const string Welt::FAHRRADTAG = "FAHRRAD";

Welt::Welt()
{
}


Welt::~Welt()
{
}

/* Funktion zum Einlesen eines Verkehrsnetz */
void Welt::vEinlesen(istream & input)
{
	stringstream ssError;
	string sType;
	int iRow = 0;

	while (input.good())
	{
		iRow++;
		input >> sType;

		try
		{
			//KREUZUNG
			if (sType == "KREUZUNG")
			{
				Kreuzung* krzg = new Kreuzung();
				input >> *krzg;
			}

			//STRASSE
			else if (sType == "STRASSE")
			{
				string NameQ, NameZ, NameW1, NameW2;
				double dLaenge, dGeschwindigkeit;
				bool bUeberholverbot;

				Weg* weg = new Weg();
				input >> NameQ >> NameZ >> NameW1 >> NameW2 >> dLaenge >> dGeschwindigkeit >> bUeberholverbot;
			}

			//PKW
			else if (sType == "PKW")
			{
				PKW* pkw = new PKW();
				input >> *pkw;
				string sKreuzung;
				double dStartZeit;

				//Speichere die Daten
				input >> sKreuzung >> dStartZeit;
				try
				{
					Kreuzung* krzg = dynamic_cast<Kreuzung*>(pkw->ptObjekt(sKreuzung));
					krzg->vAnnahme(pkw, dStartZeit);
				}
				catch(exception error)
				{
					delete pkw;

					//Zeige spezifische Fehlermeldung an
					ssError.str("");
					ssError << "ERROR ROW: " << iRow << "Name der Zielkreuzung kann nicht vergeben werden";
					throw exception(ssError.str().c_str());
				}
			}

			//Fahrrad
			else  if (sType == "FAHRRAD")
			{
				Fahrrad* fhrd = new Fahrrad();
				input >> *fhrd;
				string sKreuzung;
				double dStartZeit;

				input >> sKreuzung >> dStartZeit;
				try
				{
					Kreuzung* krzg = dynamic_cast<Kreuzung*>(fhrd->ptObjekt(sKreuzung));
					krzg->vAnnahme(fhrd, dStartZeit);
				}
				catch(exception error)
				{
					delete fhrd;

					//Zeige spezifische Fehlermeldung an
					ssError.str("");
					ssError << "ERROR ROW: " << iRow << "Name der Zielkreuzung kann nicht vergeben werden";
					throw exception(ssError.str().c_str());
				}
			}
		}
		catch(exception error)
		{
			cout << error.what() << endl;
		}
	}
}

void Welt::vSimulation()
{
}

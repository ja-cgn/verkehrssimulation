#include "Welt.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
#include <sstream>

const string Welt::KREUZUNGTAG = "KREUZUNG";
const string Welt::STRASSETAG = "STRASSE";
const string Welt::PKWTAG = "PKW";
const string Welt::FAHRRADTAG = "FAHRRAD";
vector<Kreuzung*>::iterator iterKrzg;


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
				int x, y;

				//Lese die Attributen ein
				Kreuzung* krzg = new Kreuzung();
				input >> *krzg;
				input >> x;
				input >> y;

				//Speichere die Kreuzung
				this->vectorKreuzungen.push_back(krzg);
			}

			//STRASSE
			else if (sType == "STRASSE")
			{
				string NameQ, NameZ, NameW1, NameW2;
				double dLaenge;
				int iUeberholverbot, iGeschwindigkeit, x, y, iPunkte;
				bool bUeberholverbot;
				vector<int> iCoors;

				//Lese die Attributen ein
				Weg* weg = new Weg();
				input >> NameQ >> NameZ >> NameW1 >> NameW2 >> dLaenge >> iGeschwindigkeit >> iUeberholverbot;

				//Checke Ueberholverbot syntax
				if (iUeberholverbot != 0 && iUeberholverbot != 1)
				{
					ssError.str("");
					ssError << "ERROR Row: " << iRow << " Ueberholverbot ist kein bool";
					
					throw exception(ssError.str().c_str());
				}
				else
				{
					//Verwandle in bool
					bUeberholverbot = (bool)iUeberholverbot;
				}

				//Verwandle das Tempolimit in enum
				enum Begrenzung eTempolimit;
				switch (iGeschwindigkeit)
				{
				case 1:
					eTempolimit = Innenort;
					break;
				case 2:
					eTempolimit = Landstrasse;
					break;
				case 3:
					eTempolimit = Autobahn;
					break;
				default:
					ssError.str("");
					ssError << "ERROR Row: " << iRow << " Geschwindigkeitbegrenzung ist definitert";
				}

				//Lese die Koordinaten ein
				input >> iPunkte;
				for (int i = 0; i < iPunkte; i++)
				{
					input >> x >> y;
					iCoors.push_back(x);
					iCoors.push_back(y);
				}

				//Verbinde die eingelesene Kreuzungen
				try
				{
					Kreuzung* origin = (Kreuzung*)weg->ptObjekt(NameQ);
					Kreuzung* destination = (Kreuzung*)weg->ptObjekt(NameZ);

					if (origin && destination)
					{
						origin->vVerbinde(NameW1, NameW2, dLaenge, destination, eTempolimit, bUeberholverbot);
					}
					else
					{
						throw exception();
					}
				}
				catch (exception error)
				{
					ssError.str("");
					ssError << "ERROR Row: " << iRow << " Verbindiung kann nicht hergestellt werden";
					throw exception(ssError.str().c_str());
				}

				bZeichneStrasse(NameW1, NameW2, dLaenge, iPunkte, &iCoors[0]);
			}

			//PKW
			else if (sType == "PKW")
			{
				string sKreuzung;
				double dStartZeit;

				//Lese die Attributen ein
				PKW* pkw = new PKW();
				input >> *pkw;

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
					ssError << "ERROR ROW: " << iRow << " Name der Zielkreuzung kann nicht vergeben werden";
					throw exception(ssError.str().c_str());
				}
			}

			//Fahrrad
			else  if (sType == "FAHRRAD")
			{
				int x, y;
				Fahrrad* fhrd = new Fahrrad();
				input >> *fhrd;
				string sKreuzung;
				double dStartZeit;

				input >> sKreuzung >> dStartZeit;
				input >> x >> y;
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
					ssError << "ERROR ROW: " << iRow << " Name der Zielkreuzung kann nicht vergeben werden";
					throw exception(ssError.str().c_str());
				}
			}
			else
			{
				ssError.str("");
				ssError << "ERROR ROW: " << iRow << " Syntaxfehler, Typ unbekannt";
				throw exception(ssError.str().c_str());
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
	//Fertige alle Kreuzungen ab
	if (!this->vectorKreuzungen.empty())
	{
		iterKrzg = vectorKreuzungen.begin();

		while (iterKrzg != vectorKreuzungen.end())
		{
			(*iterKrzg)->vAbfertigung();
			iterKrzg++;
		}
	}
}

#include "Weg.h"
FahrzeugeList::iterator FahrzeugeListIter;

Weg::Weg()
{
}

Weg::Weg(string sName, double dLaenge, Begrenzung eTempolimit = Autobahn)
{
}

Weg::~Weg()
{
}

void Weg::vAbfertigung()
{
	//alle auf dem Weg befindlichen Fahzeuge abfertigen
	for (FahrzeugeListIter = p_pFahrzeuge.begin; FahrzeugeListIter != p_pFahrzeuge.end; FahrzeugeListIter++)
	{
		//TODO abfertigen
	}
}


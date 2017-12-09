#include "FzgParken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

FzgParken::FzgParken()
{
}

FzgParken::FzgParken(Weg * weg, double dStartZeit)
	:FzgVerhalten(weg), p_dStartZeit(dStartZeit)
{
}


FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug* fhzg, double dZeit)
{
	if (p_dStartZeit - dZeit < EPSILON)
	{
		throw Losfahren(fhzg, this->p_pAktuellerWeg);
	}
	else
	{
		return 0.0;
	}
	
}

#include "FzgParken.h"
#include "Fahrzeug.h"


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
		exit(2);
	}
	else
	{
		return 0.0;
	}
	
}

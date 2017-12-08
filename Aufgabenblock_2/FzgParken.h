#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken();
	FzgParken(Weg* weg, double dStartZeit);
	~FzgParken();

	double dStrecke(Fahrzeug* fhzg, double dDistance);

private:

protected:
	double p_dStartZeit;

};


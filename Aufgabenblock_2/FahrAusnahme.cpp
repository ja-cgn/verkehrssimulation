#include <iostream>
#include "FahrAusnahme.h"
#include "Fahrzeug.h"

using namespace std;

FahrAusnahme::FahrAusnahme()
{
}

FahrAusnahme::FahrAusnahme(Fahrzeug * fhzg, Weg * weg)
	:p_pFhzg(fhzg), p_pWeg(weg)
{
}


FahrAusnahme::~FahrAusnahme()
{
}

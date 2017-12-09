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

void FahrAusnahme::vBearbeiten()
{
	cout << "EXCEPTION! vBearbeiten() wurde aufgerufem!\n";
	cout << "Fahzeug: " << this->p_pFhzg << "\nWeg: " << this->p_pWeg;
}

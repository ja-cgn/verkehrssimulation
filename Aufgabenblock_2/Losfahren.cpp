#include <iostream>
#include "Losfahren.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"


Losfahren::Losfahren()
{
}

Losfahren::Losfahren(Fahrzeug * fhzg, Weg * weg)
	:FahrAusnahme(fhzg, weg)
{
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << "LOSFAHREN EXCEPTION! vBearbeiten() wurde aufgerufen!\n";
	cout << "Fahzeug: " << this->p_pFhzg << "\nWeg: " << this->p_pWeg;
}

#include <iostream>
#include "Streckenende.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"


Streckenende::Streckenende()
{
}

Streckenende::Streckenende(Fahrzeug * fhzg, Weg * weg)
	:FahrAusnahme(fhzg, weg)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << "STRECKENDE EXCEPTION! vBearbeiten() wurde aufgerufem!\n";
	cout << "Fahzeug: " << this->p_pFhzg << "\nWeg: " << this->p_pWeg;
}	

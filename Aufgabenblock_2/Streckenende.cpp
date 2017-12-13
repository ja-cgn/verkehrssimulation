#include <iostream>
#include "Streckenende.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"


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
	cout << "\nSTRECKENDE EXCEPTION! vBearbeiten() wurde aufgerufen!\n";
	cout << "Fahzeug: " << &this->p_pFhzg << "\nWeg: " << &this->p_pWeg;

	//Rufe die Abgabe Fkt, wenn diese Ausnahme aufgetreten ist, um gezielt dieses Fahrzeug zu loeschen
	p_pWeg->vAbgabe(p_pFhzg);
}	

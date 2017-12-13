#include <iostream>
#include "Losfahren.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

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
	cout << "Fahzeug: " << this->p_pFhzg->sGetName() << "\nWeg: " << this->p_pWeg->sGetName();

	//Aus der liste entrefren
	p_pWeg->vAbgabe(p_pFhzg);

	//Wieder speichern, diesmal aber als Fahrendes Fahzeug
	p_pWeg->vAnnahme(p_pFhzg);
}

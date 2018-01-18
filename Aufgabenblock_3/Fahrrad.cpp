#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"
#include <iostream>

Fahrrad::Fahrrad()
	:Fahrzeug(this->p_sName, this->p_dMaxGeschwindigkeit)
{
}

Fahrrad::Fahrrad(string sName, double dVelocity)
	:Fahrzeug(sName, dVelocity)
{
	
}

Fahrrad::~Fahrrad()
{
}

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << endl;
}

void Fahrrad::ostreamAusgabe(ostream & output)
{
	Fahrzeug::ostreamAusgabe(output);
	cout << endl;
}

istream & Fahrrad::istreamEingabe(istream & input)
{
	Fahrzeug::istreamEingabe(input);

	return input;
}

void Fahrrad::vZeichnen(Weg * weg)
{
	bZeichneFahrrad(p_sName, weg->sGetName(), this->dRelPos(weg), this->dGeschwindigkeit());
}

double Fahrrad::dGeschwindigkeit()
{
	// speed should descrease with time
	// each 20 km decreases the speed to 90% of the previous speed

	double dAktuelleGeschwindigkeit = this->p_dMaxGeschwindigkeit * pow(VELOCITY_DROP_MULTIPLIER,this->p_dGesamtStrecke / VELOCITY_DROP_DIST);
	
	if(dAktuelleGeschwindigkeit < MIN_VELOCITY)
	{
		dAktuelleGeschwindigkeit = MIN_VELOCITY;
	}
	
	return dAktuelleGeschwindigkeit;
}

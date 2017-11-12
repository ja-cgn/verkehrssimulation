#include "Fahrrad.h"

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

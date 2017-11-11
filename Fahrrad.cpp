#include "Fahrrad.h"
#define MIN_VELOCITY 12.0
#define VELOCITY_DROP_MULTIPLIER 0.90
#define VELOCITY_DROP_DIST 20.0

Fahrrad::Fahrrad() : Fahrzeug()
{
}

Fahrrad::Fahrrad(string sName):Fahrzeug(this->p_sName)
{
}

Fahrrad::Fahrrad(string sName, double dVelocity):Fahrzeug(this->p_sName, this->p_dMaxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad()
{
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

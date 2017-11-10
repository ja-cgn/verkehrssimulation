#include "Fahrrad.h"

Fahrrad::Fahrrad()
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrrad::dGeschwindigkeit()
{
	// speed should descrease with time
	// each 20 km decreases the speed to 90% of the previous speed
	if (this->p_dMaxGeschwindigkeit > 12)
	{
		
		this->p_dMaxGeschwindigkeit *= 0.9;
	}
	else
	{
		this->p_dMaxGeschwindigkeit = 12;
	}
	
	return this->p_dMaxGeschwindigkeit;
}

#pragma once
#include "Fahrzeug.h"
#define MIN_VELOCITY
	
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string sName);
	Fahrrad(string sName, double dVelocity);
	~Fahrrad();

protected:
	double dGeschwindigkeit();
};


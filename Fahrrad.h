#pragma once
#include "Fahrzeug.h"
#define MIN_VELOCITY
	
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	~Fahrrad();
	double dTanken(double dMenge = -1);
	double dGeschwindigkeit();
};


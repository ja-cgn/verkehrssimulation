#pragma once
#include "Fahrzeug.h"
#define MIN_VELOCITY 12.0
#define VELOCITY_DROP_MULTIPLIER 0.90
#define VELOCITY_DROP_DIST 20.0
	
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string sName, double dVelocity);
	~Fahrrad();

	void vAusgabe();
	void ostreamAusgabe(ostream& output);
protected:
	double dGeschwindigkeit();
};


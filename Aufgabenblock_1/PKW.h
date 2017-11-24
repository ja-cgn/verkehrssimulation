#pragma once
#include "Fahrzeug.h"

class PKW :
	public Fahrzeug
{
public:
	PKW();
	PKW(string sName, double dVelocity, double dConsumption);
	PKW(string sName, double dVelocity, double dConsumption, double dTankvolume);
	~PKW();
	
	double dTanken(double dMenge);
	double dGeschwindigkeit();
	void vAbfertigung();
	void vAusgabe();
	void ostreamAusgabe(ostream& output);

private:
	double p_dVerbrauch;
	double p_dTankInhalt;
	double p_dTankvolumen;

	double dVerbrauch();
};



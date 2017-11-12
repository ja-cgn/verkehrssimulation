#pragma once
#include "Fahrzeug.h"
#define DEFAULT_TANK_VOLUME 55

class PKW :
	public Fahrzeug
{
public:
	PKW();
	PKW(string sName, double dVelocity, double dConsumption);
	PKW(string sName, double dVelocity, double dConsumption, double dTankvolume);
	~PKW();
	
	double dTanken(double dMenge = DEFAULT_TANK_VOLUME);
	double dGeschwindigkeit();
	void vAbfertigung();
	void vAusgabe();

private:
	double p_dVerbrauch;
	double p_dTankInhalt;
	double p_dTankvolumen;

	double dVerbrauch();
};



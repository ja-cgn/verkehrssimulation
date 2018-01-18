#pragma once
#include "Fahrzeug.h"

class PKW :
	public Fahrzeug
{
public:
	//Constructors & Destructors
	PKW();
	PKW(string sName, double dVelocity, double dConsumption);
	PKW(string sName, double dVelocity, double dConsumption, double dTankvolume);
	~PKW();

	//Methods
	void vAbfertigung();
	void vAusgabe();
	void ostreamAusgabe(ostream& output);
	istream& istreamEingabe(istream& input);
	void vZeichnen(Weg* weg);
	double dTanken(double dMenge);
	double dGeschwindigkeit();

private:
	double p_dVerbrauch;
	double p_dTankInhalt;
	double p_dTankvolumen;

	double dVerbrauch();
};



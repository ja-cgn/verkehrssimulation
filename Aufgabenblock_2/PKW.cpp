#include "PKW.h"
#include "Weg.h"
#include "FzgVerhalten.h"
#include "SimuClient.h"
#include <iostream>
#include <iomanip>

/* Default constructor */
PKW::PKW()
	:Fahrzeug(this->p_sName, this->p_dMaxGeschwindigkeit),
	p_dVerbrauch(this->p_dVerbrauch),
	p_dTankvolumen(DEFAULT_TANK_VOLUME)
{
	this->p_dTankInhalt = this->p_dTankvolumen / 2;
}

/* Name, velocity and consumption constructor */
PKW::PKW(string sName, double dVelocity, double dConsumption)
	:Fahrzeug(sName, dVelocity),
	p_dVerbrauch(dConsumption),
	p_dTankvolumen(DEFAULT_TANK_VOLUME)
{
	this->p_dTankInhalt = this->p_dTankvolumen / 2;
}

/* Name, velocity, consumption and tank volume constructor */
PKW::PKW(string sName, double dVelocity, double dConsumption, double dTankvolume)
	:Fahrzeug(sName, dVelocity),
	p_dVerbrauch(dConsumption),
	p_dTankvolumen(dTankvolume)
{
	this->p_dTankInhalt = this->p_dTankvolumen / 2;
}

PKW::~PKW()
{
}

/* Returns the total fuel consumption after moving the distance */
double PKW::dVerbrauch()
{
	return p_dVerbrauch * p_dGesamtStrecke / 100;
}

/* Function for refueling with default argument to fill up the tank full */
double PKW::dTanken(double dMenge = DEFAULT_TANK_VOLUME)
{
	if (this->p_dTankInhalt < DEFAULT_TANK_VOLUME)
	{
		// New fuel level after refuel
		double dNewFuel = this->p_dTankInhalt + dMenge;

		if (dNewFuel > DEFAULT_TANK_VOLUME)
		{
			// if new fuel level > tank volume, then fuel amount = tank volume
			this->p_dTankInhalt = DEFAULT_TANK_VOLUME;
			return dMenge - (dNewFuel - DEFAULT_TANK_VOLUME);
		}
		else
		{
			this->p_dTankInhalt = dNewFuel;
			return dMenge;
		}
	}
	else
	{
		return 0;
	}
}

double PKW::dGeschwindigkeit()
{
	double dAktuellerLimit = this->p_pVerhalten->getWeg()->dGetLimit();
	if (dAktuellerLimit > this->p_dMaxGeschwindigkeit || dAktuellerLimit == -1)
	{
		return this->p_dMaxGeschwindigkeit;
	}
	else
	{
		return dAktuellerLimit;
	}
}

void PKW::vAbfertigung()
{
	// Verbrauch auf Teilstrecke = v_max * delta t * verbrauch_pro_km
	double dDeltaConsumption = this->dGeschwindigkeit() * (dGlobaleZeit - this->p_dZeit) * this->p_dVerbrauch / 100;
	
	//Nur abfertigen, wenn das Tank Inhalt nach der Verbrauch immer noch positiv ist
	if(this->p_dTankInhalt - dDeltaConsumption > 0)
	{
		//update Tankinhalt
		this->p_dTankInhalt -= dDeltaConsumption;
		Fahrzeug::vAbfertigung();
	}
	else
	{
		this->p_dZeit = dGlobaleZeit;
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setiosflags(ios::right) << setw(12) << dVerbrauch() << setw(15) << this->p_dTankInhalt << resetiosflags(ios::right) << endl;
}

void PKW::ostreamAusgabe(ostream & output)
{
	Fahrzeug::ostreamAusgabe(output);
	output.flags(ios::right);
	output.width(12);
	output << this->dVerbrauch();
	output.width(15);
	output << this->p_dTankInhalt;
	cout << endl;
}

void PKW::vZeichnen(Weg * weg)
{
	bZeichnePKW(p_sName, weg->sGetName(), this->dRelPos(weg), this->dGeschwindigkeit(), p_dTankInhalt);
}

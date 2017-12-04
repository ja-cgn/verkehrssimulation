#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include <iostream>
#include <iomanip>
#include "Weg.h"

/* Default constructor */
Fahrzeug::Fahrzeug()
	:AktivesVO()
{
	vInitialisierung();
}

/* Copy Constructor */
Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug)
	:AktivesVO(fahrzeug)
{
	vInitialisierung();

	this->p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

/* Name constructor */
Fahrzeug::Fahrzeug(string sName)
	:AktivesVO(sName)
{
	vInitialisierung();
}

/* Name and velocity constructor */
Fahrzeug::Fahrzeug(string sName, double dVelocity)
	:AktivesVO(sName)
{
	vInitialisierung();
	this->p_dMaxGeschwindigkeit = dVelocity;
}

Fahrzeug::~Fahrzeug()
{
}

double Fahrzeug::dGetGesamtStrecke()
{
	return this->p_dGesamtStrecke;
}


/* Initializer function for all constructors */
void Fahrzeug::vInitialisierung()
{
	this->p_dMaxGeschwindigkeit = 0;
	this->p_dGesamtStrecke = 0;
	this->p_GesamteZeit = 0;
	this->p_pVerhalten = NULL;
}

void Fahrzeug::vAusgabe()
{
	//output the info of a vehicle according to the predefined form in main.cpp
	cout << setiosflags(ios::left) << setw(4) << this->p_iID << setw(7) << this->p_sName << ":" << resetiosflags(ios::left)
		<< setiosflags(ios::right) << setw(8) << this->p_dMaxGeschwindigkeit << setw(12) << this->p_dGesamtStrecke
		<< setw(12) << resetiosflags(ios::right);
}

void Fahrzeug::ostreamAusgabe(ostream &output)
{
	//Call the Abstract parent class output
	AktivesVO::ostreamAusgabe(output);

	//Output unique parameters
	output << ":";
	output.flags(ios::right);
	output.width(8);
	output << this->p_dMaxGeschwindigkeit;
	output.width(12);
	output << this->p_dGesamtStrecke;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return 0.0;
}

void Fahrzeug::vNeueStrecke(Weg * weg)
{
	//Erzeuge eine neue Instanz von FzgVerhalten
	FzgVerhalten* pNeuVerhalten = new FzgVerhalten(weg);

	//Speichere in Fahrzeug
	this->p_pVerhalten = pNeuVerhalten;

	//Garbage Collection
	delete pNeuVerhalten;
}

void Fahrzeug::vAbfertigung()
{
	// excute only if the last update happened before the current global time
	if (this->p_dZeit < dGlobaleZeit)
	{
		// update position
		this->p_dGesamtStrecke += p_pVerhalten->dStrecke(this, dGlobaleZeit - this->p_dZeit);

		// update clock
		this->p_dZeit = dGlobaleZeit;
	}
}

bool Fahrzeug::operator<(const Fahrzeug & fhzg)
{
	if (this->p_dGesamtStrecke < fhzg.p_dGesamtStrecke)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Fahrzeug & Fahrzeug::operator=(const Fahrzeug & fhzg)
{	
	if (this != &fhzg)
	{
		this->p_sName = fhzg.p_sName;
		this->p_dMaxGeschwindigkeit = fhzg.p_dMaxGeschwindigkeit;
		this->p_dGesamtStrecke = fhzg.p_dGesamtStrecke;
		this->p_dAbschnittStrecke = fhzg.p_dAbschnittStrecke;
		this->p_dZeit = fhzg.p_dZeit;
		this->p_GesamteZeit = fhzg.p_GesamteZeit;
	}
	return *this;
}

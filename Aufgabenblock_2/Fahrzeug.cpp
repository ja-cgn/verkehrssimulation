#include "Fahrzeug.h"

using namespace std;

/* Default constructor */
Fahrzeug::Fahrzeug()
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug)
{
	this->vInitialisierung();

	this->p_sName = fahrzeug.p_sName;
	this->p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

/* Name constructor */
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();

	this->p_sName = sName;
}

/* Name and velocity constructor */
Fahrzeug::Fahrzeug(string sName, double dVelocity)
{
	vInitialisierung();

	this->p_sName = sName;
	this->p_dMaxGeschwindigkeit = dVelocity;
}

Fahrzeug::~Fahrzeug()
{
}


/* Initializer function for all constructors */
void Fahrzeug::vInitialisierung()
{
	this->p_dMaxGeschwindigkeit = 0;
	this->p_dGesamtStrecke = 0;
	this->p_GesamteZeit = 0;
	this->p_dZeit = 0;
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
	output.flags(ios::left);
	output.width(4);
	output << this->p_iID;
	output.width(7);
	output << this->p_sName;
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
		this->p_dZeit = fhzg.p_dZeit;
		this->p_GesamteZeit = fhzg.p_GesamteZeit;
	}
	return *this;
}


ostream& operator<<(ostream& output, Fahrzeug& fhzg)
{
	fhzg.ostreamAusgabe(output);
	return output;
}

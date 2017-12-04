#include "Fahrzeug.h"

using namespace std;

//Global scope definition of the ID var to start off increments correctly
int Fahrzeug::p_iMaxID = 0; 

/* Default constructor */
Fahrzeug::Fahrzeug()
{
	vInitialisierung();

	/*
	cout << "\n------ CALLING DEFAULT CONSTRUCTOR ------" << endl;
	cout << "------ Adding the ID of the Vehicle ------" << endl;
	

	cout << "ID to add: " << p_iMaxID << endl;
	cout << "ID added: " << this->p_iID << endl;
		
	cout << "\n------ Adding Name to the Vehicle ------" << endl;
	*/
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

	/*
	cout << "\n------ CALLING NAME CONSTRUCTOR ------" << endl;
	cout << "------ Adding the ID of the Vehicle ------" << endl;
	cout << "ID to add: " << p_iMaxID << endl;
	cout << "ID added: " << this->p_iID << endl;
	cout << "\n------ Adding Name to the Vehicle ------" << endl;
	cout << "Name to add: " << name << endl;
	*/

	this->p_sName = sName;		//cout << "Added name: " << this->p_sName << endl;
}

/* Name and velocity constructor */
Fahrzeug::Fahrzeug(string sName, double dVelocity)
{
	vInitialisierung();

	/*
	cout << "\n------ CALLING NAME & VELOCITY CONSTRUCTOR ------" << endl;
	cout << "------ Adding the ID of the Vehicle ------" << endl;
	*/

	//cout << "ID to add: " << p_iMaxID << endl;
	//cout << "ID added: " << this->p_iID << endl;

	/*
	cout << "\n------ Adding Name to the Vehicle ------" << endl;
	cout << "Name to add: " << name << endl;
	*/

	this->p_sName = sName;		//cout << "Added name: " << this->p_sName << endl;

	/*
	cout << "\n------ Adding Max Velocity to the Vehicle ------" << endl;
	cout << "Velocity to add: " << velocity << endl;
	*/

	this->p_dMaxGeschwindigkeit = dVelocity; //cout << "Added velocity: " << this->p_dMaxGeschwindigkeit << endl;

}

Fahrzeug::~Fahrzeug()
{
	//cout << "\n------ CALLING DESTRUCTOR ON ID: " << this->p_iID << "------" << endl;
}


/* Initializer function for all constructors */
void Fahrzeug::vInitialisierung()
{
	this->p_iID = Fahrzeug::p_iMaxID + 1;
	Fahrzeug::p_iMaxID = this->p_iID;
	this->p_sName = "";
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
	return this->p_dMaxGeschwindigkeit;
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

void Fahrzeug::vAbfertigung()
{
	// excute only if the last update happened before the current global time
	if (this->p_dZeit < dGlobaleZeit)
	{
		// update position
		// delta(s) = v_max * delta(t) => s_new = s_old + delta(s)
		this->p_dGesamtStrecke += this->dGeschwindigkeit() * (dGlobaleZeit - this->p_dZeit);

		// update clock
		this->p_dZeit = dGlobaleZeit;
	}
}

ostream& operator<<(ostream& output, Fahrzeug& fhzg)
{
	fhzg.ostreamAusgabe(output);
	return output;
}

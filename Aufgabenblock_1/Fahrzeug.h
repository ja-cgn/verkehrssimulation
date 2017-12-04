#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#define DEFAULT_TANK_VOLUME 55


using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(const Fahrzeug& fahrzeug);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dVelocity);
	~Fahrzeug();
	void virtual vAbfertigung();
	void virtual vAusgabe();
	void virtual ostreamAusgabe(ostream& output);
	double virtual dTanken(double dMenge = DEFAULT_TANK_VOLUME);
	double virtual dGeschwindigkeit();
	bool operator<(const Fahrzeug& fhzg);
	Fahrzeug& operator=(const Fahrzeug& fhzg);

private:
	static int p_iMaxID;
	void vInitialisierung();

protected:
	int p_iID;
	string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_GesamteZeit;
	double p_dZeit;
};

ostream& operator <<(ostream& output, Fahrzeug& fhzg);
#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#define EPSILON 0.0001

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dVelocity);
	~Fahrzeug();
	void virtual vAbfertigung();
	void virtual vAusgabe();
	double virtual dTanken(double dMenge = -1);
	double virtual dGeschwindigkeit();

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
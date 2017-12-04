#pragma once
#include "AktivesVO.h"
#include <string>
#define DEFAULT_TANK_VOLUME 55
#define EPSILON 0.01
class FzgVerhalten;
extern double dGlobaleZeit;
using namespace std;

class Fahrzeug:
	public AktivesVO
{
public:
	Fahrzeug();
	Fahrzeug(const Fahrzeug& fahrzeug);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dVelocity);
	~Fahrzeug();

	double dGetGesamtStrecke();

	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual void ostreamAusgabe(ostream& output);
	virtual double dTanken(double dMenge = DEFAULT_TANK_VOLUME);
	virtual double dGeschwindigkeit();
	virtual void vNeueStrecke(Weg* weg);

	bool operator<(const Fahrzeug& fhzg);
	Fahrzeug& operator=(const Fahrzeug& fhzg);

private:
	void vInitialisierung();

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dAbschnittStrecke;
	double p_GesamteZeit;
	FzgVerhalten* p_pVerhalten;
};
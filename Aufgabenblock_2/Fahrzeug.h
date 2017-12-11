#pragma once
#include "AktivesVO.h"
#include <string>
#define DEFAULT_TANK_VOLUME 55
#define EPSILON 0.01
class FzgVerhalten;
class Weg;

extern double dGlobaleZeit;
using namespace std;

class Fahrzeug:
	public AktivesVO
{
public:
	//Constructors & Destructors
	Fahrzeug();
	Fahrzeug(const Fahrzeug& fahrzeug);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dVelocity);
	~Fahrzeug();

	//Getter functions
	double dGetGesamtStrecke();
	double dGetAbschnittStrecke();

	//Methods
	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual void ostreamAusgabe(ostream& output);
	virtual void vZeichnen(Weg* weg) = 0;
	virtual double dTanken(double dMenge = DEFAULT_TANK_VOLUME);
	virtual double dGeschwindigkeit() = 0;
	void vNeueStrecke(Weg* weg);
	void vNeueStrecke(Weg* weg, double dStartZeit);

	//Operator overloads
	bool operator<(const Fahrzeug& fhzg);
	Fahrzeug& operator=(const Fahrzeug& fhzg);

private:
	void vInitialisierung();

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dAbschnittStrecke;
	double p_dGesamteZeit;
	FzgVerhalten* p_pVerhalten;
};
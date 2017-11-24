#pragma once
#include "AktivesVO.h"
#include "Fahrzeug.h"

class Weg :
	public AktivesVO
{
public:
	Weg();
	~Weg();

private:
	double p_dLaenge;
	list<Fahzeug*> p_pFahrzeuge;

protected:

};


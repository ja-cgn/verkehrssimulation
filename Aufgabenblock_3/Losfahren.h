#pragma once
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren();
	Losfahren(Fahrzeug* fhzg, Weg* weg);
	~Losfahren();

	void vBearbeiten();
};


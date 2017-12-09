#pragma once
#include "FahrAusnahme.h"
class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende();
	Streckenende(Fahrzeug* fhzg, Weg* weg);
	~Streckenende();

	void vBearbeiten();
};


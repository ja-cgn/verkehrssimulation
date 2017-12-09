#pragma once
class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme();
	FahrAusnahme(Fahrzeug* fhzg, Weg* weg);
	virtual ~FahrAusnahme();

	virtual void vBearbeiten();
protected:
	Fahrzeug* p_pFhzg;
	Weg* p_pWeg;

};


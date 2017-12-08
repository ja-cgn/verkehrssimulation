#pragma once
class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:
	FzgVerhalten();
	FzgVerhalten(Weg* weg);
	virtual ~FzgVerhalten();

	Weg* getWeg();

	virtual double dStrecke(Fahrzeug* fhzg, double dDistance);

private:

protected:
	Weg* p_pAktuellerWeg;
};


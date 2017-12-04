#pragma once
class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:
	FzgVerhalten();
	FzgVerhalten(Weg* weg);
	~FzgVerhalten();

	virtual double dStrecke(Fahrzeug* fzhg, double dDistance);
private:

protected:

};


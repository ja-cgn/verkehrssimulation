#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg)
	:p_pAktuellerWeg(weg)
{
}

FzgVerhalten::~FzgVerhalten()
{
}

Weg * FzgVerhalten::getWeg()
{
	return this->p_pAktuellerWeg;
}

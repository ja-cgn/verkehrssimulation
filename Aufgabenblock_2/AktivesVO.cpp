#include "AktivesVO.h"
#include <iomanip>

AktivesVO::AktivesVO()
{

}

AktivesVO::~AktivesVO()
{
}

void AktivesVO::vAbfertigung()
{
}

void AktivesVO::ostreamAusgabe(ostream & output)
{
}

ostream& operator<<(ostream& output, AktivesVO & vo)
{
	// TODO: hier Rückgabeanweisung eingeben
	vo.ostreamAusgabe(output);
	return output;
}

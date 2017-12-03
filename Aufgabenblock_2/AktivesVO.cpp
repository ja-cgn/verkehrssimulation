#include "AktivesVO.h"
#include <iostream>
#include <iomanip>

using namespace std;
//Global scope definition of the ID var to start off increments correctly
int AktivesVO::p_iMaxID = 0;

/* Default constructor */
AktivesVO::AktivesVO()
{
	vInitialisierung();
}

/* Default destructor */
AktivesVO::~AktivesVO()
{
}

void AktivesVO::vInitialisierung()
{
	//Assign a unique ID and increment the max ID
	this->p_iID = AktivesVO::p_iMaxID + 1;
	AktivesVO::p_iMaxID = this->p_iID;

	//Assign common parameters
	this->p_sName = "";
	this->p_dZeit = 0;
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

#include "AktivesVO.h"

//Global scope definition of the ID var to start off increments correctly
int AktivesVO::p_iMaxID = 0;

/* Default constructor */
AktivesVO::AktivesVO()
{
	vInitialisierung();
}

/* Name constructor */
AktivesVO::AktivesVO(string sName)
{
	vInitialisierung();

	this->p_sName = sName;
}

/* Copy Constructor */
AktivesVO::AktivesVO(const AktivesVO & vo)
{
	vInitialisierung();

	this->p_sName = vo.p_sName;
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
	//Output only the name and the ID
	output.flags(ios::left);
	output.width(4);
	output << this->p_iID;
	output.width(7);
	output << this->p_sName;
}

ostream& operator<<(ostream& output, AktivesVO & vo)
{
	vo.ostreamAusgabe(output);
	return output;
}

#include "AktivesVO.h"

//Global scope definition of the ID var to start off increments correctly
int AktivesVO::p_iMaxID = 0;

map<string, AktivesVO*> AktivesVO::mObjekteMap;
map<string, AktivesVO*>::iterator pMapIter;

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
	vAddToMap(this);
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

string AktivesVO::sGetName()
{
	return this->p_sName;
}

AktivesVO * AktivesVO::ptObjekt(string sName)
{
	if (mObjekteMap.count(sName))
	{
		pMapIter = mObjekteMap.find(sName);
		return pMapIter->second;
	}
	else
	{
		throw exception("Error: Map enthaelt den gesuchten Objekt leider nicht.");
	}
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

istream & AktivesVO::istreamEingabe(istream & input)
{
	if (p_sName == "")
	{
		input >> p_sName;
		vAddToMap(this);
		return input;
	}
	else
	{
		throw exception("Error: AktivesVO wurde frueher schon erzeugt");
	}
}

void AktivesVO::vAddToMap(AktivesVO * object)
{
	if (mObjekteMap.count(object->sGetName()))
	{
		throw exception("Error: Map enthaelt den Objekt bereits");
	}
	else
	{
		mObjekteMap.emplace(object->sGetName(), object);
	}
}

ostream& operator<<(ostream& output, AktivesVO & vo)
{
	vo.ostreamAusgabe(output);
	return output;
}

istream & operator >> (istream & input, AktivesVO & vo)
{
	vo.istreamEingabe(input);
	return input;
}

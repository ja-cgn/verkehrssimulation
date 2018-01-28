#pragma once
#include <string>
#include <map>

using namespace std;

enum Begrenzung
{
	Innenort = 50,
	Landstrasse = 100,
	Autobahn = -1
};

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string sName);
	AktivesVO(const AktivesVO& vo);
	virtual ~AktivesVO();

	//Getter methods
	string sGetName();
	virtual AktivesVO* ptObjekt(string sName);

	//Methods
	virtual void vInitialisierung();
	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);
	virtual void vAddToMap(AktivesVO* object);

private:
	static int p_iMaxID;
	static map<string, AktivesVO*> mObjekteMap;

protected:
	string p_sName;
	int p_iID;
	double p_dZeit;

};

ostream& operator <<(ostream& output, AktivesVO& vo);
istream& operator >> (istream& input, AktivesVO& vo);


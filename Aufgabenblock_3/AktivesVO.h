#pragma once
#include <string>

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

	string sGetName();

	virtual void vInitialisierung();
	virtual void vAbfertigung();
	virtual void ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);

private:
	static int p_iMaxID;

protected:
	string p_sName;
	int p_iID;
	double p_dZeit;

};

ostream& operator <<(ostream& output, AktivesVO& vo);
istream& operator >> (istream& input, AktivesVO& vo);


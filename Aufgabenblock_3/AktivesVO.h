#pragma once
#include <string>

using namespace std;

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

private:
	static int p_iMaxID;

protected:
	string p_sName;
	int p_iID;
	double p_dZeit;

};

ostream& operator <<(ostream& output, AktivesVO& vo);


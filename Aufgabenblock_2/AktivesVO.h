#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

class AktivesVO
{
public:
	AktivesVO();
	virtual ~AktivesVO();

	void virtual vInitialisierung();
	void virtual vAbfertigung();
	void virtual ostreamAusgabe(ostream& output);

private:
	static int p_iMaxID;

protected:
	string p_sName;
	int p_iID;
	int p_dZeit;

};

ostream& operator <<(ostream& output, AktivesVO& vo);


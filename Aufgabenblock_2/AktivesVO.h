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

	void virtual vAbfertigung();
	void virtual ostreamAusgabe(ostream& output);

protected:
	string p_sName;
	int p_iID;
	int p_dZeit;

};

ostream& operator <<(ostream& output, AktivesVO& vo);


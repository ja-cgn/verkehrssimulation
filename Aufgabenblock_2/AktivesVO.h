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
	void virtual vAusgabe();
	void virtual ostreamAusgabe(ostream& output);

protected:
	string sName;
	int iID;
	int dZeit;

};


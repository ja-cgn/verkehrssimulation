#pragma once
#include <iostream>

using namespace std;

class Welt
{
public:

	static const string KREUZUNGTAG;
	static const string STRASSETAG;
	static const string PKWTAG;
	static const string FAHRRADTAG;

	Welt();
	~Welt();
	
	void vEinlesen(istream& input);
	void vSimulation();
};


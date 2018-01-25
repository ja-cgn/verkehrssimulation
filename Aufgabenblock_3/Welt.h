#pragma once
#include <iostream>
#include <vector>

class AktivesVO;
class Kreuzung;
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

private:
	vector<Kreuzung*> vectorKreuzungen;
};


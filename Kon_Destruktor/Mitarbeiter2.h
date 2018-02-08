#pragma once

/*
	Versuchen wir ein wenig Datenkapselung
*/

class Mitarbeiter2 {

protected:
	string name;
	int gehalt;

public:
	void setData(string n, int g)
	{
		this->name = n;
		this->gehalt = g;
	}

	void getData()
	{
		cout << "\n Name: " << name << " Gehalt: " << gehalt << endl;
	}
};
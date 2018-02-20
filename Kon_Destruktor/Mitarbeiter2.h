#pragma once

/*
	Beispiel für eine Klassendefinition (mit Datenkapselung)
*/

class Mitarbeiter2 {

protected:		// auf die Variablen kann nur ueber die
			//	Funktionen zugegriffen werden
	string name;
	int gehalt;

public:

	// Ein guter Konstruktor - Wenn nichts eingegeben wird, wird unbekannt und 0
	// eingetragen
	Mitarbeiter2(string name = "unbekannt", int gehalt = 0)
	{
		this->name = name;
		this->gehalt = gehalt;
	}
	
	void setData(string n, int g)
	{
		this->name = n;
		this->gehalt = g;
	}

	string getName()
	{
		return name;
	}
};

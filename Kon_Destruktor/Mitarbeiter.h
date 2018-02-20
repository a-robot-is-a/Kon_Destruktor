#pragma once

/*
	Beispiel für eine Klassendefinition (mit Datenkapselung)
*/

class Mitarbeiter {

protected:		// auf die Variablen (Felder) kann nur ueber die
			// Methoden zugegriffen werden
	string name;
	int gehalt;

public:

	Mitarbeiter(string name = "unbekannt", int gehalt = 0)
	{
		this->name = name;		// Ein guter Konstruktor - Wenn nichts eingegeben wird,
		this->gehalt = gehalt;		// werden unbekannt und 0 eingetragen	
	}
	
	
	
	void setData(string n, int g)
	{
		this->name = n;
		this->gehalt = g;
	}

	string getData()	// read only
	{
		return "\n Name: " + name + " Gehalt: " + to_string(gehalt);
	}
};

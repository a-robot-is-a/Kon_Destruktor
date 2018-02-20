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
	
	
	
	void setData(int g)
	{
		this->gehalt = g;
	}

	string getData()	// read only
	{
		return "Name: " + name + " Gehalt: " + to_string(gehalt);
	}
};

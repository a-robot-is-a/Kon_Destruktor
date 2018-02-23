#pragma once

/*
	Beispiel für eine Klassendefinition (mit Datenkapselung)
*/

class Mitarbeiter {

private:		// auf die Variablen (Felder) kann nur ueber die
			// Methoden zugegriffen werden
	string name;
	int gehalt;

public:

	Mitarbeiter(string n = "unbekannt", int g = 0)
	{
		name = n;		// Ein guter Konstruktor - Wenn nichts eingegeben wird,
		gehalt = g;		// werden unbekannt und 0 eingetragen	
	}

	
	void setData(int g)
	{
		gehalt = g;
	}

	string getData()	// read only
	{
		return "Name: " + name + " Gehalt: " + to_string(gehalt);
	}

	void setName(string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}
};

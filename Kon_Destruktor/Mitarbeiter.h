#pragma once

/*

* Beispiel für eine Klassendefinition

*/

class Mitarbeiter {

public:
	string name;
	int gehalt;

	// Besserer Konstruktor - Wenn nichts eingegeben wird, wird unbekannt und 0
	// eingetragen
	Mitarbeiter(string name = "unbekannt", int gehalt = 0)
	{
		this->name = name;
		this->gehalt = gehalt;
	}
	
	void befoerdern(int betrag)
	{
		gehalt = gehalt + betrag;
	}
};

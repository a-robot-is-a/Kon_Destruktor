#pragma once

/*

* Beispiel für eine Klassendefinition

*/

class Mitarbeiter {

public:
	string name;
	int gehalt;

	Mitarbeiter()
	{
		name = "unbekannt";
		gehalt = 0;
	}

	Mitarbeiter(string n, int s)
	{
		name = n;
		gehalt = s;
	}
	
	void befoerdern(int betrag)
	{
		gehalt = gehalt + betrag;
	}
};

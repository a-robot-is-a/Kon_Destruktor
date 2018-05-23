#include "Mitarbeiter.h"
using namespace mySpace;

Mitarbeiter::Mitarbeiter(string n, int g):name(n), gehalt(g)
{	}

	void Mitarbeiter::setData(int g)
	{
		gehalt = g;
	}

	string Mitarbeiter::getData()	// read only
	{
		return "Name: " + name + " Gehalt: " + to_string(gehalt);
	}

	void Mitarbeiter::setName(string n)
	{
		name = n;
	}

	string Mitarbeiter::getName()
	{
		return name;
	}


#pragma once

#include <iostream>
using namespace std;
#include <string>

class Mitarbeiter {

private:

	string name;
	int gehalt;

public:

	Mitarbeiter(string n = "unbekannt", int g = 0);

	void setData(int g);

	string getData();

	void setName(string n);

	string getName();
};

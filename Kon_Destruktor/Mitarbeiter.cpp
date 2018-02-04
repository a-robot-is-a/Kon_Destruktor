/*
Diese Quelle stellt die main.
Hier werden die Klassen aufgerufen.
*/

#include <iostream>
#include <string>
using namespace std;

#include "Mitarbeiter.h"

int main() {

	//Objekte anlegen

	Mitarbeiter jim;

	Mitarbeiter jules("Jules", 2000);

	cout << "\n jim - Objekt:" << endl;
	cout << " Name: " << jim.name << endl;
	cout << " Gehalt: " << jim.gehalt << endl;

	cout << "\n jules - Objekt:" << endl;
	cout << " Name: " << jules.name << endl;
	cout << " Gehalt: " << jules.gehalt << endl;

	// Zeiger sind Variablen, die als Werte Speicheradressen enthalten.
	// Hier ein Zeiger auf die Adresse des Datenobjekts jules.

	Mitarbeiter *ptr = &jules;
	cout << "\n Pointer - jules - Objekt:" << endl;
	cout << " Name: " << (ptr->name) << endl;

	ptr->gehalt = 5;
	cout << " Gehalt: " << (ptr->gehalt) << endl;

	return 0;
}
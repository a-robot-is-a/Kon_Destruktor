/*
Diese Quelle stellt die main.
Hier werden die Klassen aufgerufen.
*/

#include <iostream>
#include <string>
using namespace std;

#include "Mitarbeiter.h"
#include "Mitarbeiter2.h"

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

	// Ein wenig array - um die ganze Horde zu verwalten :)

	const int cap = 5;
	Mitarbeiter mitA[cap];

	for (size_t i = 0; i < cap; i++)
	{
		cout << "\n Name: " << mitA[i].name << " Gehalt: " << mitA[i].gehalt << endl;
	}

	// Hallo Roger, ein Gruss von Linux

	// Datenkapselung (Mitarbeiter2.h)

	cout << "\n Datenkapselung(Mitarbeiter2.h)" << endl;

	Mitarbeiter2 peter;
	peter.setData("Hartmann", 3500);
	peter.getData();
	
	return 0;
}

/*
	Diese Quelle stellt die main.
	Hier werden die Klassen aufgerufen.
*/

#include <iostream>
#include <string>
using namespace std;

#include "Mitarbeiter.h"
#include "Mitarbeiter2.h"
#include "Stack.h"

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


	// Datenkapselung (Mitarbeiter2.h)

	cout << "\n Datenkapselung(Mitarbeiter2.h)" << endl;

	Mitarbeiter2 peter;
	peter.setData("Hartmann", 3500);
	peter.getData();


	// Stack
	cout << "\n Hier beginnt der Stack.h" << endl;

	Stack sta(3);
	sta.push(5);

	cout << "\n Current size of stack is " << sta.size() << endl;

	sta.push(10);
	sta.push(24);

	cout << "\n Current size of stack is " << sta.size() << endl;

	// Der Stack ist voll, jetzt wird die overflow Bedingung ausgeloest

	sta.push(12);

	// Zugriff auf das oberste Element
	cout << "\n The current top element in stack is " << sta.topElement() << endl;

	return 0;
}

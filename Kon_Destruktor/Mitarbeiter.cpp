/*
	Diese Quelle stellt die main().
	Hier werden die Klassen aufgerufen.
*/

#include <iostream>
#include <string>
using namespace std;

#include "Mitarbeiter.h"
#include "Mitarbeiter2.h"
#include "Stack.h"

// Etwas GUI fuer Stack.h
int gui()
{
	char auswahl = 'x';
	cout << "\n Moechten Sie einen Stack anlegen? y/n: ";
	cin >> auswahl;

	if (auswahl == 'n')
	{
		return 0;
	}

	if(auswahl == 'y')
	{ 
		int eingabe;
		cout << "\n Geben Sie die Kapazitaet vom Stack ein: ";
		cin >> eingabe;

		Stack stack(eingabe);
		cout << "\n Der Stack hat " << eingabe << " Plaetze." << endl;

		cout << "\n Eine Zahl auf dem Stack speichern - s eingeben: " << endl;
		cout << " Eine Zahl vom Stack nehmen - d eingeben: " << endl;
		cout << " Programm verlassen - e: " << endl;
		cin >> auswahl;

		while ('e' != auswahl)
		{
			if (auswahl == 's')
			{
				int zahl;
				cout << "Geben Sie eine int-Zahl ein: ";
				cin >> zahl;
				stack.push(zahl);
				cout << "\n Der oberste Platz im Stack ist " << stack.size() << endl;
				cout << "\n Das oberste Element im Stack ist " << stack.topElement() << endl;
				cout << "\n Eine Zahl auf dem Stack speichern - s eingeben: " << endl;
				cout << " Eine Zahl vom Stack nehmen - d eingeben: " << endl;
				cout << " programm verlassen - e: " << endl;
				cin >> auswahl;
			}
			if (auswahl == 'd')
			{
				cout << "\n Das oberste Element " << stack.topElement() << " wird entfernt" << endl;
				stack.pull();
				cout << "\n Das oberste Element im Stack ist " << stack.topElement() << endl;
				cout << "\n Der oberste Platz im Stack ist " << stack.size() << endl;
				cout << "\n Eine Zahl auf dem Stack speichern - s eingeben: " << endl;
				cout << " Eine Zahl vom Stack nehmen - d eingeben: " << endl;
				cout << " programm verlassen - e: " << endl;
				cin >> auswahl;
			}
		}		
	}
	return 0;
}


int main() {

	//Objekte anlegen

	Mitarbeiter jim;	// Objekt mit dem Standard-Konstruktor 'Mitarbeiter();'

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
	cout << "\nHier beginnt der Stack.h" << endl;

	cout << "\n\nEin GUI, um etwas rumzuspielen" << endl;
	gui();

	return 0;
}

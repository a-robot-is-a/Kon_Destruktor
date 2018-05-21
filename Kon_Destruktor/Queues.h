#pragma once

#include <iostream>
using namespace std;
#include <string>

class Queues {

private:

	struct node	// Muster fuer den Compiler zum speichern dieses Typs
	{
		string data;
		node *next;
	};

	node *root;
	node *neuesElement;
	node *ptr;
	bool empty;

public:

	Queues();
	void init(); // erzeugen einer leeren Schlange
	void enter(string s); // hinzufuegen am Ende
	bool isempty(); // pruefen, ob die Schlange leer ist 
	string front(); // inspizieren Schlangenkopf
	void remove(); // entfernen des Schlangenkopfes
	void ausgabe();
};
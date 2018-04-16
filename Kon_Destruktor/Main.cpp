/*
	Diese Quelle stellt die main().
	Hier werden die Klassen aufgerufen.
*/

#include <iostream>
#include <string>
#include <thread>
using namespace std;

#include "Mitarbeiter.h"
#include "Stack.h"
#include "Queues.h"
#include "LinkedList.h"
#include "Chaining.h"
#include "FileOperation.h"


void print(LinkedList list) // threading an das System uebergeben :)
{
	list.ausgabe();
}

int main() {

	//Objekte anlegen

	Mitarbeiter jim;	// Objekt mit unbekannt und 0

	Mitarbeiter jules("Jules", 2000);	// Objekt mit Parameteruebergabe

	cout << "\n jim - Objekt: " << jim.getData() << endl;

	cout << "\n jules - Objekt: " << jules.getData() << endl;

	jules.setData(1000);	// Jules was lazy the last ten years :)


	// Zeiger sind Variablen, die als Werte Speicheradressen enthalten.
	// Hier ein Zeiger auf die Adresse des Datenobjekts jules.

	Mitarbeiter *ptr = &jules;
	cout << "\n Pointer - jules - Objekt: " << ptr->getData() << endl;


	// Ein wenig array - um die ganze Horde zu verwalten :)
	cout << "\n\n Mitarbeiter-Array" << endl;

	const int cap = 4;
	Mitarbeiter mitA[cap];

	for (size_t i = 0; i < cap; i++)
	{
		cout << "\n\t Mitarbeiter " << i  << ": " << mitA[i].getData() << endl;
	}

	mitA[0].setName("Beate");	// populate the arry a bit
	mitA[1].setName("Gisela");
	mitA[2].setName("Peter");

	// Queues
	cout << "\n\n Hier beginnt der Queues.h" << endl;
	Queues que(cap);

	for (Mitarbeiter i : mitA)	// Bereichsbaierte Vorschleife C++11
	{
		que.add(i.getName());	// Uebername der Namen von mitA[] in die Schlange
	}

	que.print();

	cout << "\n\n Etwas spielen - einen Namen aus der Schlange auf den Stack :)" << endl;
	Stack stack(cap);
	stack.push(que.firstOne());	// get the first element of the queue on stack
	cout << "\n\t Der oberste Platz im Stack ist " << stack.size() << endl;
	cout << "\n\t Das oberste Element im Stack ist " << stack.topElement() << endl;

	cout << "\n\n In der Schlange siehts jetzt so aus:" << endl;
	que.remove();	// and delete the first element from queue
	que.print();

	// again
	cout << "\n\n Etwas spielen - einen Namen aus der Schlange auf den Stack :)" << endl;
	stack.push(que.firstOne());	// Das erste Element aus der Schlange auf den Stack
	cout << "\n\t Der oberste Platz im Stack ist " << stack.size() << endl;
	cout << "\n\t Das oberste Element im Stack ist " << stack.topElement() << endl;

	cout << "\n\n In der Schlange siehts jetzt so aus:" << endl;
	que.remove();	// Das erste Element aus der Schlange entfernen
	que.print();

	// und die Schlange auffuellen :)
	cout << "\n\n Die Schlange auffuellen:" << endl;
	que.add("Petra");
	que.add("Heidi");
	que.add("Olivia");
	que.print();

	cout << "\n\n Overflow exception ausloesen" << endl;
	que.add("Anna");

	cout << "\n\n Underflow exception ausloesen" << endl;
	for (int i = 0; i < cap + 1; i++)
	{
		que.remove();
	}

	// Linked List
	cout << "\n\n Listen Test" << endl;
	LinkedList list;
	list.newElement(2, "Hallo");
	list.newElement(4, "Welt");
	list.newElement(6, "Programm");

	cout << "\n\n Neue Liste: " << endl;
	print(list);

	cout << "\n\n Loeschen 6" << endl;
	list.loeschen(6);
	print(list);

	cout << "\n\n Loeschen 2" << endl;
	list.loeschen(2);
	print(list);

	cout << "\n\n Loeschen 4" << endl;
	list.loeschen(4);
	print(list);

	// Chaining zur Kollisionsvermeidung
	cout << "\n\n Chaining zur Kollisionsvermeidung" << endl;
	Chaining chain;

	cout << "\n\n First entry - green, USB-Stick" << endl;
	chain.hashTable("green", "USB-Stick");

	cout << "\n\n Collision - green, LED" << endl;
	chain.hashTable("green", "LED");

	cout << "\n\n New entry - blue, DVD-Carton" << endl;
	chain.hashTable("blue", "DVD-Carton");

	chain.getHashTable();

	// wait, until the getList function is finished...
	thread t(&Chaining::getList,chain,7);  // get linked list at index 7

	if (t.joinable()) 
	{
		t.join();
	}
	// then everything can be saved.


	// file operations
	cout << "\n\tDateioperationen" << endl;

	FileOperation fo;

	// write to file
	string str = chain.getTableIndexesAndListDataToStore();
	fo.schreiben(str);

	// read from file
	fo.lesen();


	char end;
	cout << "\nProgramm beenden? j "; cin >> end;
	if (end == 'j') { return 0; }
	else { cin >> end; }

	return 0;
}

#include <iostream>
using namespace std;
#include <string>
#include <thread>

#include "Mitarbeiter.h"
#include "Queues.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Chaining.h"
#include "FileOperation.h"

using namespace mySpace;
using namespace Space;

void print(LinkedList list)
{
	list.ausgabe();
}

int main() {

	cout << "\n\n Mitarbeiter" << endl;

	Mitarbeiter jim;	// Objekt mit unbekannt und 0

	Mitarbeiter jules("Jules", 2000);	// Objekt mit Parameteruebergabe

	cout << "\n\n jim - Objekt: " << jim.getData() << endl;

	cout << "\n\n jules - Objekt: " << jules.getData() << endl;

	jules.setData(1000);	// Jules was lazy the last ten years :)

	// Zeiger sind Variablen, die als Werte Speicheradressen enthalten.
	// Hier ein Zeiger auf die Adresse des Datenobjekts jules.

	Mitarbeiter *ptr = &jules;
	cout << "\n\n Pointer - jules - Objekt: " << ptr->getData() << endl;



	// Ein wenig array - um die ganze Horde zu verwalten :)
	cout << "\n\n Mitarbeiter-Array" << endl;

	const int cap = 4;
	Mitarbeiter mitA[cap];

	for (size_t i = 0; i < cap; i++)
	{
		cout << "\n\t Mitarbeiter " << i << ": " << mitA[i].getData() << endl;
	}

	mitA[0].setName("Beate");	// populate the arry a bit
	mitA[1].setName("Gisela");
	mitA[2].setName("Peter");
	mitA[3].setName("Manuela");

	cout << "\n\n Nach dem populieren" << endl;

	for (size_t i = 0; i < cap; i++)
	{
		cout << "\n\t Mitarbeiter " << i << ": " << mitA[i].getData() << endl;
	}


	// Queues

	cout << "\n\n Hier beginnt der Queues.h" << endl;

	Queues que;
	que.init();

	for (Mitarbeiter i : mitA)	// Bereichsbaierte Vorschleife C++11
	{
		que.enter(i.getName());	// Uebername der Namen von mitA[] in die Schlange
	}

	thread t1(&Queues::ausgabe, que); // get a clean call
	if (t1.joinable()) { t1.join(); }

	

	// Stack und einige Spielchen

	cout << "\n\n Stack" << endl;

	cout << "\n\n Etwas spielen - einen Namen aus der Schlange auf den Stack :)" << endl;
	Stack stack(cap);
	stack.push(que.front());	// get the first element of the queue on stack
	cout << "\n\t Der oberste Platz im Stack ist " << stack.size() << endl;
	cout << "\n\t Das oberste Element im Stack ist " << stack.topElement() << endl;

	cout << "\n\n In der Schlange siehts jetzt so aus:" << endl;
	que.remove();	// and delete the first element from queue
	thread t2(&Queues::ausgabe, que); // get a clean call
	if (t2.joinable()) { t2.join(); }

	// again
	cout << "\n\n Etwas spielen - einen Namen aus der Schlange auf den Stack :)" << endl;
	stack.push(que.front());	// Das erste Element aus der Schlange auf den Stack
	cout << "\n\t Der oberste Platz im Stack ist " << stack.size() << endl;
	cout << "\n\t Das oberste Element im Stack ist " << stack.topElement() << endl;

	cout << "\n\n In der Schlange siehts jetzt so aus:" << endl;
	que.remove();	// Das erste Element aus der Schlange entfernen
	thread t3(&Queues::ausgabe, que); // get a clean call
	if (t3.joinable()) { t3.join(); };



	// Linked List

	cout << "\n\n Verlinkte Listen" << endl;

	LinkedList list(2, "Hallo");
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

	Chaining chain("green", "USB-Stick");
	cout << "\n\n First entry - green, USB-Stick" << endl;	

	cout << "\n\n Collision - green, LED" << endl;
	chain.nextElement("green", "LED");

	cout << "\n\n New entry - blue, DVD-Carton" << endl;
	chain.nextElement("blue", "DVD-Carton");

	chain.getHashTable();


	cout << "\n\n Liste mit ausgewaeltem Index" << endl;

	// wait, until the getList function is finished...
	thread t(&Chaining::getList, chain, 7);  // get linked list at index 7

	if (t.joinable())
	{
		t.join();
	}


	// then everything can be saved...

	cout << "\n\n Dateioperationen" << endl;

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

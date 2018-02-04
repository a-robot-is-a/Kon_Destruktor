/*
	Diese Quelle stellt die main.
	Hier werden die Klassen aufgerufen.
*/

#include <iostream>
using namespace std;

#include "tDatum.h"

int main() {

	tDatum::tDatum(02,02,2018);
	
	tDatum *morgen;
	morgen = new tDatum(02, 02, 2018);

	tDatum heute;
	heute.Tag = 03;

	delete morgen;	// Destruktoraufruf
	
	return 0;
}
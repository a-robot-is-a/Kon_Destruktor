#pragma once

class Chaining : public LinkedList, public Map {

private:

	LinkedList myList;	// geerbte Klassen

public:
	void daemonFunc()
	{
		// string in hashFunc einlesen, index mit Indizes in Liste vergleichen,
		// bei Uebereinstimmung in gleicher Liste speichern, sonst neue Liste.

	}

	void setData(string in)
	{
		s = in;
		hashFunc();	// Von Map.h geerbt - ueberschreibt Map::s und Map::index :)
		myList.newElement(index, s);
	}

	void getData()
	{
		myList.getData();
	}
};

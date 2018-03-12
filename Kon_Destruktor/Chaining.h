#pragma once

class Chaining : LinkedList {

private:

	string s;
	int asc = 0;
	int index = 0;

	LinkedList myList;	// geerbte Klassen

	int hashFunc()
	{
		index = accumulate(s.begin(), s.end(), 0);

		index % 13;// Modulu mit 13

		return index;
	}

public:
	void daemonFunc()
	{
		// string in hashFunc einlesen, index mit Indizes in Liste vergleichen,
		// bei Uebereinstimmung in gleicher Liste speichern, sonst neue Liste.
	}

	void setData(string in)
	{
		s = in;
		hashFunc();
		myList.newElement(index, s);
	}

	void getData()
	{
		myList.getData();
	}
};

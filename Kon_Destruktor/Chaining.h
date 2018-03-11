#pragma once

class Chaining : Map, LinkedList {

private:
	int index = 0;
	string s;

	Map myMap;	// geerbte Klassen

public:
	void setData(string in)
	{
		myMap.insertString(in);
	}

	void getData()
	{
		myMap.iterate();
	}

	void daemon()
	{

	}
};

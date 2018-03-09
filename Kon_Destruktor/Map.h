#pragma once

/*
	American Standard Code for Information Interchange
*/

#include <map>

class Map {

private:
	pair<string, int> x;
	map<string, int> m;

	int asc = 0;
	string s;
	int index = 0;

public:
	
	Map(string in)	// Konstruktor uebernimmt den string.
	{
		s = in;
	}

	int hashFunc()
	{
		for (int i = 0; i < s.length(); i++)
		{
			asc += (char)(s[i]);	// Die Zeichen aus dem String nach ASCII Dez konvertieren
									// und addieren.
		}
		index = asc % 13;// Modulu mit 13

		return index;
	}

	void insertString()
	{
		hashFunc();

		x.first = s;
		x.second = index;	// Das Paar mit dem berechneten Index.

		m.insert(x);	// In den assoziativen Container direkt addressieren.		
	}

	void iterate()
	{
		map<string, int> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\t" << it->first << " => Index " << it->second << endl;
		}
	}
};
#pragma once

/*
	American Standard Code for Information Interchange
*/

#include <map>
#include <numeric>	// fuer accumulate in hashFunc()

class Map {

protected:
	pair<int, string> x;
	map<int, string> m;

	string s;
	int index = 0;

public:	
	
	int hashFunc()
	{
		// Die Zeichen aus dem String nach ASCII Dez konvertieren
		// und addieren.
		index = accumulate(s.begin(), s.end(), 0);
		
		index = index % 29; // Modulu mit 29

		return index;
	}

	void insertString(string S)
	{
		s = S;

		hashFunc();

		x.first = index;
		x.second = s;	// Das Paar mit dem berechneten Index.

		m.insert(x);	// In den assoziativen Container direkt addressieren.		
	}

	void iterate()
	{
		map<int, string> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\t" << "Index :" << it->first << " => " << it->second << endl;
		}
	}
};
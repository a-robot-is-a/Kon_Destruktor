#pragma once

/*
	American Standard Code for Information Interchange
*/

#include <map>
#include <numeric>	// fuer accumulate in hashFunc()

class Map {

private:
	pair<string, int> x;
	map<string, int> m;

protected:
	string s;
	int index = 0;

public:	
	
	int hashFunc()
	{
		// Die Zeichen aus dem String nach ASCII Dez konvertieren
		// und addieren.
		index = accumulate(s.begin(), s.end(), 0);
		
		index % 13;// Modulu mit 13

		return index;
	}

	void insertString(string S)
	{
		s = S;

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
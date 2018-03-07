#pragma once

/*
	American Standard Code for Information Interchange
	Beispiel gefunden bei https://youtu.be/k-nSyfh6jr8
*/

#include <map>

class Map {

private:
	pair<char, int> x;
	map<char, int> m;

public:
	void makeMap()
	{
		for (char c = 'a'; c < 'z'; c++)
		{
			x.first = c;
			x.second = (int)c;

			m.insert(x);	// In den assoziativen Container direkt addressieren
		}
	}

	void iterate()
	{
		map<char, int> ::iterator it = m.begin();

		for (it = m.begin(); it != m.end(); it++)
		{
			cout << (*it).first << " " << (*it).second << endl;
		}

		cout << "Find a value" << endl;
		it = m.find('j');
		cout << (*it).second << endl;
	}
};
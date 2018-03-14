#pragma once

class Chaining : private LinkedList {

private:

	LinkedList *myList;

	pair<int, string> x;
	map<int, string> m;

	string s;
	int index = 0;

public:

	int hashFunc()
	{
		index = accumulate(s.begin(), s.end(), 0);

		index % 13;// Modulu mit 13

		return index;
	}

	void daemonFunc(string in)
	{
		// string in hashFunc einlesen, index mit Indizes in Dictionary vergleichen,
		// eine Linked List anlegen und an dem Index speichern.

		s = in;
		hashFunc();

		if (m.empty() == true)  // Create a new entry in the hash table
		{
			cerr << "\n\tNone index in hash table" << endl;

			x.first = index;
			x.second = s;	// Das Paar mit dem berechneten Index.

			m.insert(x);	// In den assoziativen Container direkt addressieren.
		}

		else  // Check if the index is already in the hash table
		{
			map<int, string> ::iterator it = m.begin();

			for (it; it != m.end(); it++)
			{

				if (index = it->first)
				{
					cerr << "\n\tIndex is already in hash table" << endl;
				}
			}
		}
	}

	void getData()
	{
		map<int, string> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\t" << "Index: " << it->first << " => " << it->second << endl;
		}
	}
};

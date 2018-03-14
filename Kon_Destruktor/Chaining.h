#pragma once

class Chaining {

private:

	struct node
	{
		string data;
		node *next;
	};

	node *neuesElement = nullptr;
	node *ptr = NULL;

	node *newList = nullptr;
	node *newPtr = NULL;

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

			neuesElement = new node();
			neuesElement->data = s;
			neuesElement->next = ptr;
			ptr = neuesElement;

			x.second = neuesElement->data;

			m.insert(x);	// In den assoziativen Container direkt addressieren.
		}

		else  // Check if the index is already in the hash table
		{
			map<int, string> ::iterator it = m.begin();

			for (it; it != m.end(); it++)
			{
				if (index == it->first)
				{
					cerr << "\n\tIndex is already in hash table" << endl;

					neuesElement = new node();
					neuesElement->data = s;
					neuesElement->next = ptr;
					ptr = neuesElement;
				}
				else
				{
					// Create a new entry in the hash table

					cout << "\n\tCreating new entry in hash Table..." << endl;
					x.first = index;

					// Assign a new linked list to the entry

					newList = new node();
					newList->data = s;
					newList->next = newPtr;
					newPtr = newList;

					x.second = newList->data;

					m.insert(x);	// In den assoziativen Container direkt addressieren.
				}
			}
		}
	}

	void getHashTable()
	{
		map<int, string> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\t" << "Index: " << it->first << " => " << it->second << endl;
		}
	}

	void getLinkedList_1()
	{
		while (ptr)
		{
			cout << "\n\t" << ptr->data << " " << ptr->next << endl;

			ptr = ptr->next;
		}
	}

	void getLinkedList_2()
	{
		while (newList)
		{
			cout << "\n\t" << newList->data << " " << newList->next << endl;

			newList = newList->next;
		}
	}
};

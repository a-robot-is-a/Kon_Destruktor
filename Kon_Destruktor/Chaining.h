#pragma once

#include <map>
#include <numeric>	// fuer accumulate in hashFunc()

class Chaining {

private:

	struct node
	{
		string data;
		node *next;
	};

	node *root = NULL;
	node *neuesElement = NULL;
	node *ptr = NULL;

	pair<int, node*> x;
	map<int, node*> m;

	string colorIndex, obj;
	int index = 0;

public:

	int hashFunc()
	{
		index = accumulate(colorIndex.begin(), colorIndex.end(), 0);

		index = index % 29;	// Modulu mit 29

		return index;
	}

	int hashTable(string color, string objekt)
	{
		colorIndex = color;
		obj = objekt;

		hashFunc();

		if (m.empty() == true)  // Create a new entry in a new hash table
		{
			cout << "\n\tCreating hash table" << endl;

			x.first = index;	// Color index of list adress

			neuesElement = new node();
			neuesElement->data = obj;
			neuesElement->next = NULL;

			ptr = root = neuesElement;

			x.second = root;	// Store the list root.			

			m.insert(x);	// Store index and list root in the hash table.

			return 0; // exit
		}

		// Check if the index is already in the hash table

		map<int, node*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			if (index == it->first)
			{
				cout << "\n\tIndex is already in hash table" << endl;
				cout << "\n\tAdding a new link" << endl;

				// get the list at index and add the entry

				neuesElement = new node();
				neuesElement->data = obj;
				neuesElement->next = NULL;

				ptr->next = neuesElement;
				ptr = neuesElement;

				return 0;	// exit
			}
		}

		// Create a new entry in the hash table

		cout << "\n\tCreating new index in hash Table..." << endl;

		x.first = index;	// Index of list root adress
		x.second = nullptr;

		// Assign a new linked list to the entry

		neuesElement = new node();
		neuesElement->data = obj;
		neuesElement->next = NULL;

		ptr = root = neuesElement;

		x.second = root;	// Store the list root.			

		m.insert(x);	// Store index and list root in the hash table.

		return 0;
	}

	void getHashTable()
	{
		map<int, node*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\tCurrently in hash table" << endl;

			cout << "\n\t\t" << "Index: " << it->first << " Adress: "
				<< it->second << endl;

			cout << "\n\t\t" << it->second << " " << it->second->data // bug

				<< " => " << it->second->next << endl;
		}
	}

	void getList(int in) // get color for index from user :)
	{
		map<int, node*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			if (in == it->first)
			{
				cout << "\n\n Stored list at index " << in << "	" << it->second << endl;
				cout << "\n Data of the links: ";

				while (it->second)
				{
					cout << " " << it->second->data;
					it->second = it->second->next;
				}
				cout << endl;
			}
		}
	}
};

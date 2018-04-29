#include "Chaining.h"
using namespace Space;

	struct no
	{
		string data;
		no *next;
	};

	no *ro = NULL;
	no *nEle = NULL;
	no *pt = NULL;

	pair<int, no*> x;
	map<int, no*> m;

	string colorIndex, obj;
	int index;

	Chaining::Chaining(string color, string object):colorIndex(color),obj(object)
	{
		hashFunc();

		// Create a new entry in a new hash table
		
		cout << "\n\tCreating hash table" << endl;

		x.first = index;	// Color index of list address

		nEle = new no();
		nEle->data = obj;
		nEle->next = NULL;

		pt = ro = nEle;

		x.second = ro;	// Store the list root.			

		m.insert(x);	// Store index and list root in the hash table.
	}


	int Chaining::hashFunc()
	{
		index = accumulate(colorIndex.begin(), colorIndex.end(), 0);

		index = index % 29;	// Modulu mit 29

		return index;
	}

	int Chaining::nextElement(string color, string object)
	{
		colorIndex = color;
		obj = object;

		hashFunc();

		// Check if the index is already in the hash table

		map<int, no*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			if (index == it->first)
			{
				cout << "\n\tIndex is already in hash table" << endl;
				cout << "\n\tAdding a new link" << endl;

				// get the list at index and add the entry

				nEle = new no();
				nEle->data = obj;
				nEle->next = NULL;

				pt->next = nEle;
				pt = nEle;

				return 0;	// exit
			}
		}

		// Create a new entry in the hash table

		cout << "\n\tCreating new index in hash Table..." << endl;

		x.first = index;	// Index of list root adress
		x.second = nullptr;

		// Assign a new linked list to the entry

		nEle = new no();
		nEle->data = obj;
		nEle->next = NULL;

		pt = ro = nEle;

		x.second = ro;	// Store the list root.			

		m.insert(x);	// Store index and list root in the hash table.

		return 0;
	}

	void Chaining::getHashTable()
	{
		map<int, no*> ::iterator it = m.begin();

		cout << "\n\n Currently in hash table" << endl;

		for (it; it != m.end(); it++)
		{
			cout << "\n\t\t" << "Index: " << it->first << " Address: "
				<< it->second << endl;

			cout << "\n\t\t" << it->second << " " << it->second->data // bug

				<< " => " << it->second->next << endl;
		}
	}

	void Chaining::getList(int in) // get color for index from user :)
	{
		map<int, no*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			if (in == it->first)
			{
				cout << "\n\t\tStored list at index " << in << " - " << it->second << endl;
				cout << "\n\t\tData of the links: ";

				while (it->second)
				{
					cout << " " << it->second->data;
					it->second = it->second->next;
				}
				cout << endl;
			}
		}
	}

	string Chaining::getTableIndexesAndListDataToStore()
	{
		map<int, no*> ::iterator it = m.begin();
		string str;
		stringstream stream;

		cout << "\n\t" << "Get all possible indexes..." << endl;

		for (it; it != m.end(); it++)
		{
			cout << "\n\t\t" << "Index: " << it->first << endl;

			stream << it->first;

			cout << "\n\t\tStoring list data..." << endl;

			while (it->second)
			{
				//get the data of the list				
				stream << " " << it->second->data;

				it->second = it->second->next;
			}
			stream << "\n";
		}
		str = stream.str();

		return str;
	}


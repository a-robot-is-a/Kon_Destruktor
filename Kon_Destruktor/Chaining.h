#pragma once

class Chaining {

private:

	struct node
	{
		string data;
		node *next;
	};

	node *neuesElement = nullptr;

	pair<int, node*> x;
	map<int, node*> m;

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
		s = in;

		hashFunc();	// return index

		if (m.empty() == true)  // Create a new entry in the hash table
		{
			cerr << "\n\tCreating new index in hash table" << endl;

			x.first = index;	// Index of list head adress

			neuesElement = new node();
			neuesElement->data = s;
			neuesElement->next = x.second;
			x.second = neuesElement;	// Store the list head pointer.			

			m.insert(x);	// Store index and list adress - hash table.
		}

		else  // Check if the index is already in the hash table
		{
			map<int, node*> ::iterator it = m.begin();

			for (it; it != m.end(); it++)
			{
				if (index == it->first)
				{
					cerr << "\n\tIndex is already in hash table" << endl;

					// get the list at index and add the entry

					x.second = new node();
					x.second->data = s;
					x.second->next = it->second;
					it->second = x.second;
				}

				else
				{
					// Create a new entry in the hash table

					cout << "\n\tCreating new entry in hash Table..." << endl;

					x.first = index;	// Index of list head adress

					// Assign a new linked list to the entry

					neuesElement = new node();
					neuesElement->data = s;
					neuesElement->next = x.second;
					x.second = neuesElement;	// Store the list head pointer.			

					m.insert(x);	// Store index and list adress - hash table.
				}
			}
		}
	}

	void getHashTable()
	{
		map<int, node*> ::iterator it = m.begin();

		for (it; it != m.end(); it++)
		{
			cout << "\n\t" << "Index: " << it->first << " => " << it->second << endl;

			while (x.second)
			{
				cout << "\n\t" << x.second << " => " << x.second->data

					<< " " << x.second->next << endl;

				x.second = x.second->next;
			}			
		}
	}
};

#pragma once

class LinkedList {

private:

	struct node
	{
		int index;
		string data;
		node *next;
	};

	node *neuesElement = NULL;
	node *ptr = NULL;

public:

	void newElement(int index, string s)
	{
		neuesElement = new node(); // neuesElement zeigt auf Objekt
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = ptr;
		ptr = neuesElement;	// ptr zeigt auf neues Element	
	}

	void erstesElementLoeschen()
	{
		for (neuesElement; neuesElement->next != NULL; neuesElement = neuesElement->next)
		{
			if (neuesElement->next->next == NULL) // is first node
			{
				neuesElement->next = NULL;
				break;
			}
		}
	}

	void loeschen(int in)
	{
		while (neuesElement->index != in)
		{
			neuesElement = neuesElement->next;

			if (neuesElement->next->next == NULL) // is last node?
			{
				neuesElement->next = NULL;
				break;
			}
		}
	}

	void loeschen2(int in)
	{
		for (neuesElement; neuesElement->index != in; neuesElement = neuesElement->next)
		{
			if (neuesElement->next->index == in) // is internal node?
			{				
				neuesElement->next = neuesElement->next->next;				
				
				break;
			}
		}
	}

	void ausgabe()
	{
		while (ptr)
		{
			cout << "\n\t" << ptr << " " << ptr->index << " " << ptr->data
				<< " => " << ptr->next << endl;

			ptr = ptr->next;
		}
	}
};
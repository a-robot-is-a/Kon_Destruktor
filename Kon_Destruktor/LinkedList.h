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

	void erstesElementLoeschen(int in) // is first node
	{
		while (neuesElement->index != in)
		{			
			if (neuesElement->next->next == NULL)
			{
				neuesElement->next = NULL;

				break;
			}
			neuesElement = neuesElement->next;
		}
	}

	void letztesElementLoeschen(int in) // is last node
	{
		node *zeiger = NULL;

		while (neuesElement->next != NULL)
		{
			if (neuesElement->index == in)
			{
				zeiger = neuesElement->next;

				delete neuesElement;

				neuesElement = zeiger;

				break;
			}
			neuesElement = neuesElement->next;
		}
	}

	void mittElementLoeschen(int in) // is internal node
	{
		for (neuesElement; neuesElement->index != in; neuesElement = neuesElement->next)
		{
			if (neuesElement->next->index == in)
			{				
				neuesElement->next = neuesElement->next->next;				
				
				break;
			}
		}
	}

	void ausgabe()
	{
		while (neuesElement != NULL)
		{
			cout << "\n\t" << neuesElement << " " << neuesElement->index << " " << neuesElement->data
				<< " => " << neuesElement->next << endl;

			neuesElement = neuesElement->next;
		}
	}
};
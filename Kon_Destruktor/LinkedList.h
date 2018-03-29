#pragma once

class LinkedList {

private:

	struct node
	{
		int index;
		string data;
		node *next;
	};

	node *root = NULL;
	node *neuesElement = NULL;
	node *ptr = NULL;

public:

	void newElement(int index, string s)
	{

		if (neuesElement == NULL)
		{
			neuesElement = new node();
			neuesElement->index = index;
			neuesElement->data = s;
			neuesElement->next = NULL;

			ptr = root = neuesElement;
		}
		else
		{
			neuesElement = new node();
			neuesElement->index = index;
			neuesElement->data = s;
			neuesElement->next = NULL;

			ptr->next = neuesElement;	// das letzte Element zeigt auf das neue Element
			ptr = neuesElement;			// das neue Element wird zum Letzten
		}

	}

	// TODO - Exception Handling fuer falsche Index-Eingabe :)

	void loeschen(int in)
	{
		node *zeiger = root;

		while (zeiger != NULL)
		{
			if (zeiger->next->index == in && zeiger->next->next != NULL)
			{
				zeiger->next = zeiger->next->next;
				break;
			}
			else
			{
				if (zeiger->next->index == in && zeiger->next->next == NULL) // delete tail (bug area)
				{
					ptr = zeiger;
					zeiger->next = NULL;
					break;
				}
				else
				{
					if (zeiger->index == in) // delete root
					{
						zeiger = root->next;
						delete root;
						root = zeiger;
						break;
					}
				}
			}
			zeiger = zeiger->next;
		}
	}

	void ausgabe()
	{
		while (root != NULL)
		{
			cout << "\n\t\t" << root << " " << root->index << " "
				<< root->data << " => " << root->next << endl;

			root = root->next;
		}
	}
};


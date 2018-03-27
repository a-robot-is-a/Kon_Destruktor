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

	void loeschen(int in)
	{
		node *zeiger = NULL;

		bool smile = false;

		while (root->index != in)
		{
			if (root->next->index == in && root->next->next != NULL)
			{
				root->next = root->next->next;
				smile = true;
				break;
			}
			else
			{
				if (root->next->next == NULL) // delete tail (bug area)
				{
					root->next = NULL;
					smile = true;
					break;
				}
			}
			root = root->next;
		}
		if (smile == false)	// delete root
		{
			zeiger = root->next;
			delete root;
			root = zeiger;
		}
	}

	void ausgabe()
	{
		node *zeiger = root;

		while (zeiger != NULL)
		{
			cout << "\n\t\t" << zeiger << " " << zeiger->index << " "
				<< zeiger->data << " => " << zeiger->next << endl;

			zeiger = zeiger->next;
		}
	}
};


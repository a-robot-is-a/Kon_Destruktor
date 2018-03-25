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
		neuesElement = new node();
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = ptr;
		ptr = neuesElement;
	}

	void loeschen(int in)
	{
		node *zeiger = NULL;
		node *zeiger1 = NULL;

		if (neuesElement != NULL)
		{
			while (neuesElement->next != NULL)
			{
				if (neuesElement->index == in) // first node
				{
					zeiger = neuesElement->next;
					delete neuesElement;
					neuesElement = zeiger;
					break;
				}
				else
				{
					zeiger = neuesElement;

					while (zeiger->next != NULL)
					{
						zeiger1 = zeiger->next;

						if (zeiger1->index == in && zeiger1->next != NULL)
						{
							zeiger->next = zeiger1->next;
							delete zeiger1;
							break;
						}
						//
						else
						{
							if (zeiger1->next == NULL)
							{
								zeiger->next = zeiger1->next; // bug :)
								delete zeiger1;
								break;
							}
						}
						//
						zeiger = zeiger1;
					}
				}
			}
		}
		else { cout << "\n\tKeine Daten zum loeschen" << endl; }
	}

	void ausgabe()
	{
		while (neuesElement)
		{
			cout << "\n\t" << neuesElement << " " << neuesElement->index << " "
				<< neuesElement->data << " => " << neuesElement->next << endl;

			neuesElement = neuesElement->next;
		}
	}
};

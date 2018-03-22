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

	void Loeschen(int in)
	{
		node *zeiger;

		while (neuesElement->index != in)
		{
			if (neuesElement->next->index == in) // first node
			{
				zeiger = neuesElement->next;

				delete neuesElement;

				neuesElement = zeiger;

				break;
			}
			else
			{
				if (neuesElement->next->next == NULL) // last node
				{
					neuesElement->next = NULL;	// bug

					break;
				}
				else
				{
					if (neuesElement->next->index == in) // internal node
					{
						neuesElement->next = neuesElement->next->next;
					}

					break;

				}

			}
			neuesElement = neuesElement->next;
		}
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

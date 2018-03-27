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

		bool smile = false;

		while (neuesElement->index != in)
		{
			if (neuesElement->next->index == in )
			{
				neuesElement->next = neuesElement->next->next;
				smile = true;
				break;
			}
			else
			{
				if (neuesElement->next->next == NULL) // bug area
				{
					zeiger = neuesElement->next;
					neuesElement->next = zeiger->next;
					delete zeiger;
					smile = true;
					break;
				}
			}
			neuesElement = neuesElement->next;
		}
		if (smile == false)
		{
			zeiger = neuesElement->next;
			delete neuesElement;
			neuesElement = zeiger;
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

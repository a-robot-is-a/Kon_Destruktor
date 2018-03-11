#pragma once

class LinkedList {

private:
	struct node
	{
		int index;
		string data;
		node *next;
	};

	node *neuesElement = nullptr;

	node *ptr = NULL;

public:	

	LinkedList(int index, string s)
	{
		// Den Kopf erstellen
		neuesElement = new node();
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = ptr;
		ptr = neuesElement;
	}
	
	void nachfolger(int index, string s)
	{
		neuesElement = new node();
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = ptr;
		ptr = neuesElement;
	}

	void getData()
	{
		while (ptr)
		{
			cout << "\n\t" << ptr->index << " " << ptr->data << " " << ptr->next << endl;

			ptr = ptr->next;
		}
	}
};
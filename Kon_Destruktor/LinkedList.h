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

	void newElement(int index, string s)
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
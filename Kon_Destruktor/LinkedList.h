#pragma once

class LinkedList {

private:
	struct node
	{
		int index;
		string data;
		struct node *next = nullptr;
	};

public:
	LinkedList(int index, string s)
	{
		// Den Kopf erstellen
		node *head = new node();
		head->index = index;
		head->data = s;
		head->next = NULL;
	}
	
	void nachfolger(int index, string s)
	{
		node *neuesElement = new node();
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = neuesElement;
	}
};